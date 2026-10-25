class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        //using kahns algo
        vector<vector<int>> adj(n);
        for(vector<int> &it:pre)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(n,0);
        for(vector<int> &it:pre)
        {
            indegree[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        if(indegree[i]==0)
        q.push(i);
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            //cout<<current<<" ";
            for(int &it:adj[current])
            {
                indegree[it]--;
                if(!indegree[it])
                q.push(it);
            }
        }
        //after queue is processed, check 
        for(int &it:indegree)
        if(it)
        return false;
        return true;
    }
};