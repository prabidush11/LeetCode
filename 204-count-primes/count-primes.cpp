class Solution {
public:
    void sieve(vector<int> &primes)
    {
        int i,j,m=primes.size(),n=m-1;
        //long long j;
        //int go=pow(n,1/2);
        for(i=2;i*1ll*i<=n;i++)
        {
            if(primes[i])
            {
                for(j=i*i;j<=n;j+=i)
                {
                    primes[j]=0;
                    
                }
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