class Solution {
    bool bfs(vector<vector<int>>&adj,vector<int>&visited,int start)
    {
        queue<int>q;
        visited[start]=1;
        q.push(start);
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            for(auto it:adj[current])
            {
                if(visited[it]==0)
                {
                    visited[it]=(visited[current]==1)?2:1;
                    q.push(it);
                }
                else if(visited[it]==visited[current])
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        //using bfs first maybe
        int n=adj.size();
        vector<int> visited(n,0);//0-not visited 1-red 2-blue
        for(int i=0;i<n;i++)
        {
            if(!visited[i] && !bfs(adj,visited,i))
            return false;
        }
        return true;
    }
};