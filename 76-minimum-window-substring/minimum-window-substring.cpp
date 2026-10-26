class Solution {
    bool all_zeroes(unordered_map<char, int>& mp) {
        for (auto it : mp) {
            if (it.second < 0) return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

        unordered_map<char, int> mp;

        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]--;
        }

        int left = 0, right = 0;
        int ansleft = 0, ansright = 0;
        int minlength = INT_MAX;

        while (right < s.size()) {
            while (!all_zeroes(mp) && right < s.size()) {
                mp[s[right]]++;
                right++;
            }

            if (!all_zeroes(mp)) break;

            while (all_zeroes(mp) && left < right) {
                mp[s[left]]--;
                left++;
            }

            int start = left - 1;
            int len = right - start;

            if (len < minlength) {
                minlength = len;
                ansleft = start;
                ansright = right - 1;
            }

        }

        if (minlength == INT_MAX) return "";

        return s.substr(ansleft, minlength);
    }
};