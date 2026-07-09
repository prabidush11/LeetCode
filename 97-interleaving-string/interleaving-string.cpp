class Solution {
    int t[101][101];
public:
    bool check(string &s1, string &s2, string &s3, int n1, int n2, int n3)
    {
        // Base case
        if(t[n1][n2]!=-1) return t[n1][n2];
        if (n1 == 0 && n2 == 0 && n3 == 0)
            return t[n1][n2]=true;

        bool take1 = false, take2 = false;

        if (n1 > 0 && s1[n1 - 1] == s3[n3 - 1])
            take1 = check(s1, s2, s3, n1 - 1, n2, n3 - 1);

        if (n2 > 0 && s2[n2 - 1] == s3[n3 - 1])
            take2 = check(s1, s2, s3, n1, n2 - 1, n3 - 1);

        return t[n1][n2]=take1 || take2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        memset(t,-1,sizeof(t));
        if (n1 + n2 != n3)
            return false;

        return check(s1, s2, s3, n1, n2, n3);
    }
};