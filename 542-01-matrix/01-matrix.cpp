class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        // push all 0s first
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    pq.push({0, {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        while(!pq.empty())
        {
            auto [dist, pos] = pq.top();
            pq.pop();

            auto [cx, cy] = pos;

            // up
            if(cx > 0 && !visited[cx - 1][cy])
            {
                visited[cx - 1][cy] = true;
                mat[cx - 1][cy] = dist + 1;
                pq.push({dist + 1, {cx - 1, cy}});
            }

            // down
            if(cx < n - 1 && !visited[cx + 1][cy])
            {
                visited[cx + 1][cy] = true;
                mat[cx + 1][cy] = dist + 1;
                pq.push({dist + 1, {cx + 1, cy}});
            }

            // left
            if(cy > 0 && !visited[cx][cy - 1])
            {
                visited[cx][cy - 1] = true;
                mat[cx][cy - 1] = dist + 1;
                pq.push({dist + 1, {cx, cy - 1}});
            }

            // right
            if(cy < m - 1 && !visited[cx][cy + 1])
            {
                visited[cx][cy + 1] = true;
                mat[cx][cy + 1] = dist + 1;
                pq.push({dist + 1, {cx, cy + 1}});
            }
        }

        return mat;
    }
};