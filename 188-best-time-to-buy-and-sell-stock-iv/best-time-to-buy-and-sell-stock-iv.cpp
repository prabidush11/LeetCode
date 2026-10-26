class Solution {
    int t[101][1001][2];
    int profit(vector<int>&prices,int k,int idx,bool holding)
    {
        //base case
        if(t[k][idx][holding]!=-1) return t[k][idx][holding];
        if(idx==prices.size()) return t[k][idx][holding]=0;
        //choice diagram
        if(k==0)
        {
            if(holding)
            return t[k][idx][holding]=max(prices[idx],profit(prices,k,idx+1,holding));
            else
            return 0;
        }
        else
        {
            if(holding)
            {
                return t[k][idx][holding]=max(prices[idx]+profit(prices,k,idx+1,false),profit(prices,k,idx+1,true));
            }
            else
            {
                return t[k][idx][holding]=max(profit(prices,k-1,idx+1,true)-prices[idx],profit(prices,k,idx+1,false));
            }
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return profit(prices,k,0,false);
    }
};