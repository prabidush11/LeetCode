class Solution {
    //int t[5001][1002][2];

    int solve(vector<int>& prices,int idx,int holding,bool prev,vector<vector<vector<int>>>&t)
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
                prices[idx]-holding+solve(prices,idx+1,1001,true,t),
                solve(prices,idx+1,holding,false,t)
            );
        }
        else
        {
            //not holding
            if(prev==true)
            {
                //wait for cooldown period
                return t[idx][holding][prev]=solve(prices,idx+1,1001,false,t);
            }
            else
            {
                return t[idx][holding][prev]=max(
                    solve(prices,idx+1,prices[idx],false,t),
                    solve(prices,idx+1,1001,false,t)
                );
            }
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        //memset(t,-1,sizeof(t));
        vector<vector<vector<int>>>t(prices.size()+1,vector<vector<int>>(1002,vector<int>(2,-1)));
        return solve(prices,0,1001,false,t);
    }
};