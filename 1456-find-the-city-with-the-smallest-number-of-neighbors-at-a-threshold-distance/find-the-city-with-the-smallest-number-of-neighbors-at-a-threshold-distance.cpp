class Solution {
    int count(vector<vector<pair<int,int>>>&adj,int& threshold,int start)
    {
        //using dijkstra now
        int n=adj.size();
        vector<int>distance(n,-1);
        vector<bool>explored(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,start});
        distance[start]=0;
        while(!pq.empty())
        {
            auto[dist,current]=pq.top();
            pq.pop();
            explored[current]=true;
            for(auto it:adj[current])
            {
                if(!explored[it.first])
                {
                    if(distance[it.first]==-1 || distance[it.first]>dist+it.second)
                    {
                        if(dist+it.second<=threshold)
                        {distance[it.first]=dist+it.second;
                        pq.push({distance[it.first],it.first});}
                    }
                }
            }
        }
        //dijkstra done
        //now i have the nearest path to every vertex right
        //lets see
        //cout<<start<<" : ";
        int count=0;
        for(auto it:distance)
        {
            if(it>0)
            count++;
        }
        //cout<<endl;
        return count;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        //first thing is to make the adj matrix only
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        //question is saare nodes ka threshold diatnec pe kitne cities hai ye khojo
        //sawaal ye hai
        vector<int>cities(n,0);
        for(int i=0;i<n;i++)
        {
            int start=i;
            cities[start]=count(adj,threshold,start);
        }
        int ans=0,maxcities=INT_MAX;
        for(int i=0;i<n;i++)
        if(maxcities>=cities[i])
        {maxcities=cities[i];
        ans=i;}
        return ans;
    }
};