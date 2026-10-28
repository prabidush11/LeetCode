   bool cmp(pair<string,int>&a,pair<string,int>&b)
    {
        if(a.second==b.second) return a.first<b.first;
        else
        return a.second<b.second;
    }
class Solution {
 
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& adj, int id, int level) {
        int n=adj.size();
        vector<int> lvl(n,-1);
        lvl[id]=0;
        queue<pair<int,int>>q;
        q.push({id,0});
        while(!q.empty())
        {
            int siz=q.size();
            for(int i=0;i<siz;i++)
            {
                auto [current,clevel]=q.front();
                q.pop();
                for(auto it:adj[current])
                {
                    if(lvl[it]==-1)
                    {
                        lvl[it]=clevel+1;
                        q.push({it,lvl[it]});
                    }
                }
            }
        }
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            if(lvl[i]==level)
            {
                for(auto it:watchedVideos[i])
                {
                    mp[it]++;
                }
            }
        }
        vector<pair<string,int>> vt;
        vector<string> ans;
        for(auto it:mp)
        {
            vt.push_back({it.first,it.second});
        }
        sort(vt.begin(),vt.end(),cmp);
        for(auto it:vt)
        ans.push_back(it.first);
        return ans;
    }
};