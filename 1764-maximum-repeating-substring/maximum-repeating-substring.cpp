class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        int n = sequence.size(), m = word.size();

        for (int i = 0; i <= n - m; i++) {
            int cnt = 0;
            while (i + (cnt + 1) * m <= n &&
                   sequence.substr(i + cnt * m, m) == word) {
                cnt++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};