class Solution {
public:
    using ll = long long;

    struct Node {
        ll cnt;
        ll sum;
    };

    Node dp[32][2];
    bool vis[32][2];
    int bits[32];
    int N;

    Node dfs(int pos, bool tight) {
        if (pos == 32)
            return {1, 0};

        if (vis[pos][tight])
            return dp[pos][tight];

        vis[pos][tight] = true;

        Node res = {0, 0};

        int lim = tight ? bits[pos] : 1;
        int nbit = (N >> (31 - pos)) & 1;

        for (int b = 0; b <= lim; b++) {
            if (nbit && b) continue;          // (n & x) must be 0

            bool ntight = tight && (b == lim);
            Node nxt = dfs(pos + 1, ntight);

            res.cnt += nxt.cnt;
            res.sum += nxt.sum + (1LL * b << (31 - pos)) * nxt.cnt;
        }

        return dp[pos][tight] = res;
    }

    long long calc(long long limit) {
        if (limit < 0) return 0;

        for (int i = 0; i < 32; i++)
            bits[i] = (limit >> (31 - i)) & 1;

        memset(vis, 0, sizeof(vis));
        return dfs(0, true).sum;
    }

    long long sumOfGoodIntegers(int n, int k) {
        N = n;
        long long L = max(1, n - k);
        long long R = 1LL * n + k;

        return calc(R) - calc(L - 1);
    }
};