class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        int m=edges.size();
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<bool>explored(n,false);
        vector<double> probability(n,0);
        priority_queue<pair<double,int>>pq;
        pq.push({1,start_node});
        probability[start_node]=1;
        while(!pq.empty())
        {
            auto [prob,current]=pq.top();
            cout<<current<<" ";
            pq.pop();
            explored[current]=true;
            for(auto it:adj[current])
            {
                if(!explored[it.first])
                {
                    if(probability[it.first]<prob*it.second)
                    {
                        probability[it.first]=prob*it.second;
                        pq.push({probability[it.first],it.first});
                    }
                }
            }
        }
        return probability[end_node];
    }
};