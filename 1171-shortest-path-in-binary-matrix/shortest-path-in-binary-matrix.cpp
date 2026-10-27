class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n=grid.size();
        vector<vector<int>> visited(n,vector<int>(n,-1));
        visited[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int> drow={0,0,1,-1,1,1,-1,-1};
        vector<int> dcol={1,-1,0,0,-1,1,-1,1};
        while(!q.empty())
        {
            auto [row,col]=q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                if(row+drow[i]>=0 && row+drow[i]<n && col+dcol[i]>=0 && col+dcol[i]<n)
                {if(visited[row+drow[i]][col+dcol[i]]==-1 && grid[row+drow[i]][col+dcol[i]]==0)
                {
                    visited[row+drow[i]][col+dcol[i]]=visited[row][col]+1;
                    q.push({row+drow[i],col+dcol[i]});
                }}
            }
        }
        return visited[n-1][n-1];
    }
};