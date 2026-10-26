class Solution {
    void bfs(vector<vector<char>>& grid,int row,int col)
    {
        queue<pair<int,int>>q;
        q.push({row,col});
        grid[row][col]='0';
        vector<int> dirx={0,0,1,-1};
        vector<int> diry={1,-1,0,0};
        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                if(i+dirx[k]>=0 && i+dirx[k]<grid.size() && j+diry[k]>=0 && j+diry[k]<grid[0].size() && grid[i+dirx[k]][j+diry[k]]=='1')
                {
                    grid[i+dirx[k]][j+diry[k]]='0';
                    q.push({i+dirx[k],j+diry[k]});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};