class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> out_adj(n),in_adj(n);
        for(auto it:trust)
        {
            out_adj[it[0]-1].push_back(it[1]-1);
            in_adj[it[1]-1].push_back(it[0]-1);
        }
        for(int i=0;i<n;i++)
        {
            if(out_adj[i].size()==0 && in_adj[i].size()==n-1)
            {
                return i+1;
            }
        }
        return -1;
    }
};