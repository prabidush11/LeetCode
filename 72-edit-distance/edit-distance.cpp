class Solution {
    //int t[502][502];
public:
//using memo

    // int call(string&s1,string&s2,int n,int m)
    // {
    //     //base case
    //     if(t[n][m]!=-1) return t[n][m];
    //     if(m==0) return n;
    //     if(n==0) return m;
    //     //choice diagram
    //     if(s1[n-1]==s2[m-1])
    //     return t[n][m]=call(s1,s2,n-1,m-1);
    //     else
    //     return t[n][m]=1+min({call(s1,s2,n,m-1),call(s1,s2,n-1,m),call(s1,s2,n-1,m-1)});
    // }

    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        int t[n+1][m+1];
        for(int i=0;i<=n;i++)
        t[i][0]=i;
        for(int i=0;i<=m;i++)
        t[0][i]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    t[i][j]=t[i-1][j-1];
                }
                else
                {
                    t[i][j]=1+min(t[i][j-1],min(t[i-1][j],t[i-1][j-1]));
                }
            }
        }
        return t[n][m];
    }
};