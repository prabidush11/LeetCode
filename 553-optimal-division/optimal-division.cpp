class Solution {
    pair<float,float> t[10][10];
    bool calc[10][10];
    pair<float,float> solve(vector<int>&nums,int i,int j)
    {
        //base case
        if(i>j) return {1,1};
        if(i==j) return t[i][j]={nums[i],nums[i]};
        if(calc[i][j]) return t[i][j];
        //recursion
        float maxans=INT_MIN*1.0,minans=INT_MAX*1.0;
        for(int k=i;k<j;k++)
        {
            float temp_maxans=solve(nums,i,k).first/solve(nums,k+1,j).second;
            float temp_minans=solve(nums,i,k).second/solve(nums,k+1,j).first;
            maxans=max(maxans,temp_maxans);
            minans=min(minans,temp_minans);
        }
        calc[i][j]=true;
        return t[i][j]={maxans,minans};
    }
    void paren(vector<pair<int,int>>& brackets,
           int i, int j, float ans, bool isRight)
{
    if(i == j)
        return;

    // Parentheses are required only for a non-leaf right child
    if(isRight)
        brackets.push_back({i,j});

    for(int k = i; k < j; k++)
    {
        if(ans == t[i][k].first / t[k+1][j].second)
        {
            paren(brackets, i, k, t[i][k].first, false);
            paren(brackets, k+1, j, t[k+1][j].second, true);
            break;
        }
        else if(ans == t[i][k].second / t[k+1][j].first)
        {
            paren(brackets, i, k, t[i][k].second, false);
            paren(brackets, k+1, j, t[k+1][j].first, true);
            break;
        }
    }
}
public:
    string optimalDivision(vector<int>& nums) {
        memset(calc,false,sizeof(calc));
        pair<float,float> ans=solve(nums,0,nums.size()-1);
        //cout<<ans.first<<" "<<ans.second;
        //now i have the ways to reach the minimum stored in the array t;

        //for every answer, check which k makes the answer
        float answer=ans.first;
        vector<pair<int,int>> brackets;
        //brackets.push_back({0,nums.size()-1},answer);
        paren(brackets,0,nums.size()-1,answer,false);
        for(auto it:brackets)
        cout<<it.first<<" "<<it.second<<"\n";

        //now when the bracets are ready, ii need to print the string now
        string s="";
        vector<bool> start(nums.size(),false),end(nums.size(),false);
        for(auto it:brackets)
        {
            start[it.first]=true;
            end[it.second]=true;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(start[i])
            s+="(";
            if(i!=nums.size()-1)
            s+=to_string(nums[i])+"/";
            else
            s+=to_string(nums[i]);
            if(end[i])
            s+=")";
        }
        
        return s;
    }
};