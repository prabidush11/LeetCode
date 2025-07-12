class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        vector<long long> dp(prices.size(),1);
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]==prices[i-1]-1)
            dp[i]=dp[i-1]+1;
        }
        //int pdt=1;
        long long ans=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(dp[i+1]==1)
            ans+=(dp[i]*(dp[i]+1))/2;
        }
        ans+=(dp[prices.size()-1]*(dp[prices.size()-1]+1))/2;
        //ans+=dp[prices.size()-1];
        return ans;
    }
};