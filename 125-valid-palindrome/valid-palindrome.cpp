class Solution {
public:

    bool palin(string &s,int i,int &n)
    {
        if(2*i>=n) return true;
        if(s[i]!=s[n-i-1]) return false;
        return palin(s,i+1,n);
    }

    bool isPalindrome(string s) {
        string toWork="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i]))
            toWork+=tolower(s[i]);
        }
        cout<<toWork;
         n=toWork.size();
        return palin(toWork,0,n);
    }
};