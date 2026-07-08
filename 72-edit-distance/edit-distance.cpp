class Solution {
    int t[502][502];
public:
//using memo

    int call(string&s1,string&s2,int n,int m)
    {
        //base case
        if(t[n][m]!=-1) return t[n][m];
        if(m==0) return n;
        if(n==0) return m;
        //choice diagram
        if(s1[n-1]==s2[m-1])
        return t[n][m]=call(s1,s2,n-1,m-1);
        else
        return t[n][m]=1+min({call(s1,s2,n,m-1),call(s1,s2,n-1,m),call(s1,s2,n-1,m-1)});
    }

    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        memset(t,-1,sizeof(t));
        return call(s1,s2,n,m);
    }
};