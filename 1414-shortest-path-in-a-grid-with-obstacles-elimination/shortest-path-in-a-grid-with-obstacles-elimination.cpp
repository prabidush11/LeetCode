class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<pair<int,int>, pair<int,int>>> q;
        vector<vector<int>> best(n, vector<int>(m, -1));

        q.push({{0, 0}, {k - grid[0][0], 0}});
        best[0][0] = k - grid[0][0];

        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [pos, state] = q.front();
            q.pop();

            auto [row, col] = pos;
            auto [K, dist] = state;

            if (row == n - 1 && col == m - 1)
                return dist;

            for (int i = 0; i < 4; i++) {
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int newK = K - grid[nr][nc];

                if (newK < 0)
                    continue;

                if (best[nr][nc] >= newK)
                    continue;

                best[nr][nc] = newK;
                q.push({{nr, nc}, {newK, dist + 1}});
            }
        }

        return -1;
    }
};