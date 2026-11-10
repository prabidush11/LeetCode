class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int> dp(n+1, INT_MAX);

        dp[n] = 0;

        for(int i=n-1; i>=0; i--) {
            int ca = INT_MAX, cb = INT_MAX, cc = INT_MAX;

            if(i+1 <= n)
                ca = cost[i] + 1 + dp[i+1];

            if(i+2 <= n)
                cb = cost[i+1] + 4 + dp[i+2];

            if(i+3 <= n)
                cc = cost[i+2] + 9 + dp[i+3];

            dp[i] = min({ca, cb, cc});
        }

        return dp[0];
    }
};