class Solution {
    public int climbStairs(int n, int[] cost) {
        int[] dp = new int[n + 1];

        Arrays.fill(dp, Integer.MAX_VALUE);

        // Base case
        dp[n] = 0;

        // Bottom-up traversal
        for (int i = n - 1; i >= 0; i--) {

            int ca = Integer.MAX_VALUE;
            int cb = Integer.MAX_VALUE;
            int cc = Integer.MAX_VALUE;

            if (i + 1 <= n)
                ca = cost[i] + 1 + dp[i + 1];

            if (i + 2 <= n)
                cb = cost[i + 1] + 4 + dp[i + 2];

            if (i + 3 <= n)
                cc = cost[i + 2] + 9 + dp[i + 3];

            dp[i] = Math.min(ca, Math.min(cb, cc));
        }

        return dp[0];
    }
}