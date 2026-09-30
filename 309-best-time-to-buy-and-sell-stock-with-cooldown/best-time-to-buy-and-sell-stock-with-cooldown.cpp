class Solution {
    int t[5001][2][2];

    int solve(vector<int>& prices,int idx,bool holding,bool prev)
    {
        //base case
        if(idx>=prices.size()) return 0;
        if(t[idx][holding][prev]!=-1)
        return t[idx][holding][prev];
        //choice diagram
        if(holding)
        {
            //holding a stock
            return t[idx][holding][prev]=max(
                prices[idx]+solve(prices,idx+1,false,true),
                solve(prices,idx+1,true,false)
            );
        }
        else
        {
            //not holding
            if(prev==true)
            {
                //wait for cooldown period
                return t[idx][holding][prev]=solve(prices,idx+1,false,false);
            }
            else
            {
                return t[idx][holding][prev]=max(
                    solve(prices,idx+1,true,false)-prices[idx],
                    solve(prices,idx+1,false,false)
                );
            }
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        //vector<vector<vector<int>>>t(prices.size()+1,vector<vector<int>>(1002,vector<int>(2,-1)));
        return solve(prices,0,false,false);
    }
};