class Solution {
public:
    static vector<int> pivot;

    static long long cross(const vector<int>& O, const vector<int>& A, const vector<int>& B) {
        return 1LL * (A[0] - O[0]) * (B[1] - O[1]) -
               1LL * (A[1] - O[1]) * (B[0] - O[0]);
    }

    static long long dist(const vector<int>& A, const vector<int>& B) {
        long long dx = A[0] - B[0];
        long long dy = A[1] - B[1];
        return dx * dx + dy * dy;
    }

    static bool cmpPivot(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    }

    static bool cmpAngle(const vector<int>& a, const vector<int>& b) {
        long long c = cross(pivot, a, b);

        if (c != 0)
            return c > 0;

        return dist(pivot, a) < dist(pivot, b);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {

        int n = trees.size();
        if (n <= 3) return trees;

        sort(trees.begin(), trees.end(), cmpPivot);

        pivot = trees[0];

        sort(trees.begin() + 1, trees.end(), cmpAngle);

        // Reverse the last collinear group
        int i = n - 1;
        while (i > 0 && cross(pivot, trees[i - 1], trees[n - 1]) == 0)
            i--;

        reverse(trees.begin() + i, trees.end());

        vector<vector<int>> st;

        st.push_back(trees[0]);
        st.push_back(trees[1]);

        for (int i = 2; i < n; i++) {

            while (st.size() >= 2 &&
                   cross(st[st.size() - 2], st.back(), trees[i]) < 0) {
                st.pop_back();
            }

            st.push_back(trees[i]);
        }

        return st;
    }
};

vector<int> Solution::pivot;