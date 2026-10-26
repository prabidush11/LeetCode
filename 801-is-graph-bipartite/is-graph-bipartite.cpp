class Solution {
    bool dfs(vector<vector<int>>& adj,vector<int>&visited,int current,int parent)
    {
        if(parent==-1) visited[current]=1;
        else
        visited[current]=visited[parent]==1?2:1;
        for(auto it:adj[current])
        {
            if(visited[it]==visited[current])
            {
                return false;
            }
            else if(visited[it]==0)
            {
                if(!dfs(adj,visited,it,current))
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        //using dfs now
        int n=adj.size();
        vector<int>visited(n,0);
        //0 not visited 1 red 2 blue
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(!dfs(adj,visited,i,-1)) return false;
            }
        }
        return true;
    }
};