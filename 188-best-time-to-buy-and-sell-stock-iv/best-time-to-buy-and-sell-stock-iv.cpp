class Solution {
    int t[101][1001][2];

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        memset(t, 0, sizeof(t));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int trans = 0; trans <= k; trans++) {

                // Not holding
                if (trans == 0) {
                    t[trans][idx][0] = 0;
                } else {
                    t[trans][idx][0] = max(
                        t[trans - 1][idx + 1][1] - prices[idx],
                        t[trans][idx + 1][0]
                    );
                }

                // Holding
                t[trans][idx][1] = max(
                    prices[idx] + t[trans][idx + 1][0],
                    t[trans][idx + 1][1]
                );
            }
        }

        return t[k][0][0];
    }
};