class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        int i2=0,i3=0,i5=0;
        vector<int> ugly(n);
        ugly[0]=1;
        for(int i=1;i<n;i++)
        {
            ugly[i]=min({ugly[i2]*2,ugly[i3]*3,ugly[i5]*5});
            if(ugly[i2]*2==ugly[i]) i2++;
            if(ugly[i3]*3==ugly[i]) i3++;
            if(ugly[i5]*5==ugly[i]) i5++; 
        }
        return ugly[n-1];
    }
};