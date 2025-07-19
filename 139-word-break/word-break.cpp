class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        unordered_set<string> mp;
        for(auto& it : wordDict) mp.insert(it);

        dp[n] = true;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j <= n; j++) {
                if(mp.find(s.substr(i, j - i)) != mp.end() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
