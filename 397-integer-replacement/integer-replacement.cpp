class Solution {
    long long solve(long long n,unordered_map<long long,long long>&t)
    {
        //base case
        if(n<1) return INT_MAX;
        if(n==1) return t[n]=0;
        if(t.find(n)!=t.end()) return t[n];
        //choice diagram
        if(n%2==0)
        return t[n]=1+solve(n/2,t);
        else
        return t[n]=1+min(solve(n+1,t),solve(n-1,t));
    }
public:
    int integerReplacement(int n) {
        unordered_map<long long,long long> t;
        return (int)solve(n,t);
    }
};