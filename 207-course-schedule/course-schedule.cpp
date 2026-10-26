class Solution {
    bool dfs(vector<vector<int>>&adj,vector<bool>&path,vector<bool>&visited,int current)
    {
        visited[current]=true;
        path[current]=true;
        for(int it:adj[current])
        {
            if(path[it])
            return true;
            if(!visited[it] && dfs(adj,path,visited,it))
            return true;
        }
        path[current]=false;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        //will solve this question using dfs+path tracking tomorrow
        vector<vector<int>> adj(n);
        for(auto it:pre)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> path(n,false),visited(n,false);
        int i;
        for(i=0;i<n;i++)
        {
            if(!visited[i] && dfs(adj,path,visited,i))
            break;
        }
        if(i==n) return true;
        return false;
    }
};