class Solution {
    int t[51][51][51];
    int solve(int&n,int &m,int maxMove,int crow,int ccol)
    {
        //base case
        if(crow<0 || ccol<0 || crow>=n || ccol>=m)
        {
            //exit;
            return 1;
        }
        if(t[crow][ccol][maxMove]!=-1) return t[crow][ccol][maxMove];
        if(maxMove==0) return t[crow][ccol][maxMove]=0;

        //choice diagram
        //can go in four directions
        return t[crow][ccol][maxMove]=(
    (
        solve(n,m,maxMove-1,crow+1,ccol)
        + solve(n,m,maxMove-1,crow-1,ccol)
    ) % ((int)1e9 + 7)
    +
    (
        solve(n,m,maxMove-1,crow,ccol-1)
        + solve(n,m,maxMove-1,crow,ccol+1)
    ) % ((int)1e9 + 7)
) % ((int)1e9 + 7);
    }
public:
    int findPaths(int n, int m, int maxMove, int crow, int ccol) {
        memset(t,-1,sizeof(t));
        return solve(n,m,maxMove,crow,ccol);
    }
};