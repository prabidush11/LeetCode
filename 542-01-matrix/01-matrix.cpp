class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;

        // Put all 0s into queue
        // Mark 1s as unvisited using -1
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                }
                else
                {
                    mat[i][j] = -1;
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx >= 0 && nx < n &&
                   ny >= 0 && ny < m &&
                   mat[nx][ny] == -1)
                {
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return mat;
    }
};