class Solution {
    int count(int n)
    {
        int c=0;
        while(n)
        {
            if(n&1) c++;
            n=n>>1;
        }
        return c;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++)
        ans[i]=count(i);
        return ans;
    }
};