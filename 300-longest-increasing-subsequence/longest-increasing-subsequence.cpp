class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        nums.push_back(INT_MAX);
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<=n;j++)
            if(nums[j]>nums[i])
            dp[i]=max(dp[i],1+dp[j]);
            ans=max(ans,dp[i]);
        }
        for(auto it:dp)cout<<it<<" ";
        return ans;
    }
};