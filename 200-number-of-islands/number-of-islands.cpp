class Solution {
    void dfs(vector<vector<char>>& grid,int row,int col,vector<int>&drow,vector<int>&dcol)
    {
        grid[row][col]='0';
        for(int k=0;k<4;k++)
        {
            if(row+drow[k]>=0 && row+drow[k]<grid.size() && col+dcol[k]>=0 && col+dcol[k]<grid[0].size() && grid[row+drow[k]][col+dcol[k]]=='1')
            dfs(grid,row+drow[k],col+dcol[k],drow,dcol);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<int> drow={0,0,1,-1};
        vector<int> dcol={1,-1,0,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    dfs(grid,i,j,drow,dcol);
                }
            }
        }
        return ans;
    }
};