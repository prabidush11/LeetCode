class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        int n=nums.size();
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            //find min among the nums[i] next numbers
            int mini=dp[i+1];
            for(int j=i+2;j<=min(n-1,i+nums[i]);j++)
            if(dp[j]!=1e6)
            mini=min(mini,dp[j]);
            dp[i]=1+mini;
            if(nums[i]==0) dp[i]=1e6;
        }
        return dp[0];
    }
};