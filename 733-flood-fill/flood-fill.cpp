class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];

        if (original == color)
            return image;

        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<int, int>> q;

        q.push({sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = color;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check BEFORE pushing
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !visited[nr][nc] &&
                    image[nr][nc] == original) {

                    visited[nr][nc] = true;
                    image[nr][nc] = color;

                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};