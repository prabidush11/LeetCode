class Solution {
public:
    void sieve(vector<int> &primes)
    {
        int i,m=primes.size(),n=m-1;
        long long j;
        for(i=2;i<=n;i++)
        {
            if(primes[i])
            {
                for(j=i*1ll*i;j<=n;j+=i)
                primes[j]=0;
            }
        }
    }
    int countPrimes(int n) {
        vector<int> primes(n+1,1);
        sieve(primes);
        int count=0;
        for(int i=2;i<n;i++)
        if(primes[i])
        count++;
        return count;
    }
};