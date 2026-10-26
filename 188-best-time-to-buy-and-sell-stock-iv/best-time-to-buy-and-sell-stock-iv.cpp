
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            k + 1, vector<vector<int>>(n + 1, vector<int>(2, 0))
        );

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int trans = 0; trans <= k; trans++) {

                // Not holding a stock
                dp[trans][idx][0] = max(
                    dp[trans][idx + 1][0],
                    trans > 0
                        ? dp[trans - 1][idx + 1][1] - prices[idx]
                        : 0
                );

                // Holding a stock
                dp[trans][idx][1] = max(
                    dp[trans][idx + 1][1],
                    prices[idx] + dp[trans][idx + 1][0]
                );
            }
        }

        return dp[k][0][0];
    }
};
