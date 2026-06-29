class Solution {
public:
    bool isSubsequence(string t, string s) {
        int itr=0, matched=0;
        int ss=s.size(),ts=t.size();
        while(itr<ss && matched<ts)
        {
            if(s[itr]==t[matched])
            {
                itr++;
                matched++;
            }
            else
            {
                itr++;
            }
        }
        cout<<matched;
        if(matched==ts)
        return true;
        return false;
    }
};