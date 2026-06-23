class Solution {
public:
    int popcount(int n)
    {
        int ans=0;
        while(n>0)
        {
            if(n&1) ans++;
            n/=2;
        }
        return ans;
    }
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        return popcount(ans);
    }
};