class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) count++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(count==0) return 0;
        //there are count fresh oranges, we need to rot them
        //first push all the rotten oranges
        //pushed?
        bool finished=false;
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            ans++;
            for(int i=0;i<sz;i++)
            {
                //this is type of level order traversal
                auto [cx,cy]=q.front();
                q.pop();
                if(grid[cx][cy]==0) continue;
                //check for others
                if(cx>0 && grid[cx-1][cy]==1)
                {
                    //apple was fresh, rot it
                    grid[cx-1][cy]=2;
                    q.push({cx-1,cy});
                    count--;
                }
                if(cx<n-1 && grid[cx+1][cy]==1)
                {
                    //apple was fresh, rot it
                    grid[cx+1][cy]=2;
                    q.push({cx+1,cy});
                    count--;
                }
                if(cy>0 && grid[cx][cy-1]==1)
                {
                    //apple was fresh, rot it
                    grid[cx][cy-1]=2;
                    q.push({cx,cy-1});
                    count--;
                }
                if(cy<m-1 && grid[cx][cy+1]==1)
                {
                    //apple was fresh, rot it
                    grid[cx][cy+1]=2;
                    q.push({cx,cy+1});
                    count--;
                }
            }
        }
        if(count==0) return ans-1;
        return -1;
    }
};