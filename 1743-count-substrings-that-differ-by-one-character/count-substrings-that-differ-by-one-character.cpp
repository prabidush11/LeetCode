class Solution {
public:
    int countSubstrings(string s, string t) {
        vector<vector<int>> match(s.size(),vector<int>(t.size(),0));
        int n=s.size(),m=t.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i]!=t[j])
                {
                    match[i][j]=1;
                    ans++;
                }
            }
        }

        //now for all substrings 
        for(int windowSize=2;windowSize<=min(n,m);windowSize++)
        {
            for(int i=0;i<=n-windowSize;i++)
            {
                for(int j=0;j<=m-windowSize;j++)
                {
                    int count1=0;
                    for(int k=0;k<windowSize;k++)
                    if(match[i+k][j+k]==1)
                    count1++;
                    if(count1==1) ans++;
                }
            }
        }
        return ans;
    }
};