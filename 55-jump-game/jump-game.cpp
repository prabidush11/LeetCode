class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>dp(n,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--)
        {
            bool ans=false;
            for(int j=i+1;j<=min(n-1,i+nums[i]);j++)
            {
                ans=ans||dp[j];
                if(ans) break;
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};