class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=prices[n-1];
        int ans=0;
        for(int i=n-2;i>=0;i--)
        {
            maxi=max(maxi,prices[i]);
            ans=max(ans,maxi-prices[i]);
        }
        return ans;
    }
};