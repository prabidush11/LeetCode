class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto it:pre)
        adj[it[1]].push_back(it[0]);
        vector<int> indegree(n,0);
        for(auto it:pre)
        {
            indegree[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        if(!indegree[i])
        q.push(i);
        vector<int>ans;
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            ans.push_back(current);
            for(auto it:adj[current])
            {
                indegree[it]--;
                if(!indegree[it])
                q.push(it);
            }
        }
        for(auto it:indegree)
        if(it!=0) return {};
        return ans;

    }
};