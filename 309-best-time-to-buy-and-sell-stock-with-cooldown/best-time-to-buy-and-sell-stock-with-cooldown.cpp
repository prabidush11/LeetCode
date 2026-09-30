class Solution {
    int t[5001][1002][2];

    int solve(vector<int>& prices,int idx,int holding,bool prev)
    {
        //base case
        if(idx>=prices.size()) return 0;
        if(t[idx][holding][prev]!=-1)
        return t[idx][holding][prev];
        //choice diagram
        if(holding!=1001)
        {
            //holding a stock
            return t[idx][holding][prev]=max(
                prices[idx]-holding+solve(prices,idx+1,1001,true),
                solve(prices,idx+1,holding,false)
            );
        }
        else
        {
            //not holding
            if(prev==true)
            {
                //wait for cooldown period
                return t[idx][holding][prev]=solve(prices,idx+1,1001,false);
            }
            else
            {
                return t[idx][holding][prev]=max(
                    solve(prices,idx+1,prices[idx],false),
                    solve(prices,idx+1,1001,false)
                );
            }
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(prices,0,1001,false);
    }
};