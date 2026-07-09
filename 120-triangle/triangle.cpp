class Solution {
    int t[201][201];
public:
    int sum(vector<vector<int>>& triangle,int i,int j,int n)
    {
        //base case
        if(t[i][j]!=1e7) return t[i][j];
        if (i == n - 1)
        return t[i][j]=triangle[i][j];
        return t[i][j]=triangle[i][j]+min(sum(triangle,i+1,j,n),sum(triangle,i+1,j+1,n));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=0;i<=200;i++)
        for(int j=0;j<=200;j++)
        t[i][j]=1e7;
        return sum(triangle,0,0,triangle.size());
    }
};