class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        int n=grid.size();
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp.insert({grid[i][j],{i,j}});
            }
        }
        vector<pair<int,int>>dir={{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
        pair<int,int>current={0,0};
        int number=0;
        while(number<n*n-1)
        {
            int next=number+1;
            //cout<<next<<" "<<mp[next].first<<mp[next].second<<"\n";
            //check if mp[next] is one of the 8 directions or not
            bool found=false;
            for(int i=0;i<8;i++)
            {
                if(mp[next].first == current.first + dir[i].first &&
   mp[next].second == current.second + dir[i].second)
                {
                    current=mp[next];
                    found=true;
                    break;
                }
            }
            if(!found) return false;
            number=next;
        }
        return true;
    }
};