class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int kmax) {
        //using a queue with k stops as the point to focus
        //and just updting the destination
        vector<int> distance(n,-1);
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        distance[src]=0;
        queue<pair<int,pair<int,int>>>q;//k node dist
        q.push({0,{src,0}});
        while(!q.empty())
        {
            auto [k,snd]=q.front();
            auto [node,dist]=snd;
            //cout<<k<<" "<<node<<" "<<dist<<"\n";
            q.pop();
            if(k==kmax+1)
            break;
            for(auto it:adj[node])
            {
                if(distance[it.first]==-1 || distance[it.first]>dist+it.second)
                {
                    distance[it.first]=dist+it.second;
                    q.push({k+1,{it.first,distance[it.first]}});
                }
            }
        }
        return distance[dst];
    }
};