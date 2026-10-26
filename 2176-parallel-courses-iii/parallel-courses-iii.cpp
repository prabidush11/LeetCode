class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> fastest(n,0);
        //calculate indegree
        vector<int> indegree(n,0);
        for(auto it:relations)
        {
            indegree[it[1]-1]++;
        }
        //adj matrix
        vector<vector<int>> adj(n);
        for(auto it:relations)
        {
            adj[it[0]-1].push_back(it[1]-1);
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                fastest[i]=time[i];
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            for(auto it:adj[current])
            {
                fastest[it]=max(fastest[it],time[it]+fastest[current]);
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        //return the maximum time
        int ans=0;
        for(auto it:fastest)
        ans=max(ans,it);
        return ans;
    }
};