
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1), pge(n, -1);
        stack<int> st;

        // Next Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                pge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (nge[i] != -1 && nge[i] - i >= 2)
                ans++;

            if (pge[i] != -1 && i - pge[i] >= 2)
                ans++;
        }

        return ans;
    }
};
