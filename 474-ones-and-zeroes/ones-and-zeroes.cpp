class Solution {
    int t[601][101][101];
    int solve(vector<string>& strs, int m, int n,int idx)
    {
        //count 1s ands 0s;
        if(idx==strs.size()) return 0;
        if(t[idx][m][n]!=-1) return t[idx][m][n];
        int ones=0,zeroes=0;
        int s=strs[idx].size();
        for(int i=0;i<s;i++)
        {
            if(strs[idx][i]=='1')
            ones++;
            else
            zeroes++;
        }
        if(zeroes<=m && ones<=n)
        {
            //take or not take
            return t[idx][m][n]=max(1+solve(strs,m-zeroes,n-ones,idx+1),solve(strs,m,n,idx+1));
        }
        else
        return t[idx][m][n]=solve(strs,m,n,idx+1);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(strs,m,n,0);
    }
};