class Solution {
public:
    int solve(vector<int>& nums,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        //int n=nums.size();
        int maxi=INT_MIN;
        int coins=0;
        for(int idx=i;idx<=j;idx++)
        {
            coins=nums[i-1]*nums[idx]*nums[j+1]+solve(nums,i,idx-1,dp)+solve(nums,idx+1,j,dp);
            if(coins>maxi) maxi=coins;
        }
        dp[i][j]=maxi;
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        //int ans=INT_MIN;
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //size became n+2, 0 to n+1
        return solve(nums,1,n,dp);
    }
};