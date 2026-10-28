class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m=heights[0].size();
        pq.push({0,{0,0}});
        vector<int> drow={0,0,1,-1};
        vector<int> dcol={1,-1,0,0};
        vector<vector<bool>> explored(n,vector<bool>(m,false));
        vector<vector<int>> diff(n,vector<int>(m,-1));
        diff[0][0]=0;
        while(!pq.empty())
        {
            auto [difference,coord]=pq.top();
            auto [row,col]=coord;
            pq.pop();
            explored[row][col]=true;
            for(int i=0;i<4;i++)
            {
                //if the coordinate exists
                if(row+drow[i]>=0 && row+drow[i]<n && col+dcol[i]>=0 && col+dcol[i]<m)
                {
                    //if it is not locked
                    if(!explored[row+drow[i]][col+dcol[i]])
                    {
                        //if it is less
                        if(diff[row+drow[i]][col+dcol[i]]==-1 || diff[row+drow[i]][col+dcol[i]]>max(difference,abs(heights[row][col]-heights[row+drow[i]][col+dcol[i]])))
                        {
                            diff[row+drow[i]][col+dcol[i]]=max(difference,abs(heights[row][col]-heights[row+drow[i]][col+dcol[i]]));
                            pq.push({diff[row+drow[i]][col+dcol[i]],{row+drow[i],col+dcol[i]}});
                        }
                    }
                }
            }
        }
        return diff[n-1][m-1];
    }
};