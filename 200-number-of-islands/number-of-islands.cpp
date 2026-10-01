class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!='0')
                {
                    q.push({i,j});
                    while(!q.empty())
                    {
                        auto [cx,cy]=q.front();
                        q.pop();
                        if(cx>=1 && grid[cx-1][cy]=='1')
                        {
                            q.push({cx-1,cy});
                            grid[cx-1][cy]='0';
                        }
                        
                        if(cx<=n-2 && grid[cx+1][cy]=='1') 
                        {
                            q.push({cx+1,cy});
                            grid[cx+1][cy]='0';
                        }

                        if(cy>=1 && grid[cx][cy-1]=='1')
                        {
                            q.push({cx,cy-1});
                            grid[cx][cy-1]='0';
                        }
                        
                        if(cy<=m-2 && grid[cx][cy+1]=='1')
                        {
                            q.push({cx,cy+1}); 
                            grid[cx][cy+1]='0';
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};