class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-3;i>=0;i--)
        {
            int maxi=nums[i+2];
            for(int j=i+3;j<n;j++)
            {
                maxi=max(maxi,nums[j]);
            }
            nums[i]+=maxi;
        }
        int maxi=0;
        for(auto it:nums)
        maxi=max(maxi,it);

        return maxi;
    }
};