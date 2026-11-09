class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int x : nums) mp[x]++;

        for (int x : target) {
            mp[x]--;
            if (mp[x] < 0) return 0;
        }

        // Find matching prefix
        int prefix = 0;

        while (prefix < n && nums[prefix] == target[prefix]) {
            prefix++;
        }

        // Find longest non-increasing suffix
        int sorted = n - 1;

        while (sorted > 0 && target[sorted - 1] >= target[sorted]) {
            sorted--;
        }

        return max(0, min(prefix, n - 1) - sorted + 1);;
    }
};