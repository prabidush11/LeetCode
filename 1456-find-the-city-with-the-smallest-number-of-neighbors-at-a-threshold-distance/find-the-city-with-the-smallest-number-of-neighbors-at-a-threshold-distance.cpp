class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        //first thing is to make the adj matrix only
        //using flloyd warshall
        //all pair shortest path
        //visit a to b eveythime from node 0 to n-1
        //first make the adjcency matrix
        vector<vector<int>> matrix(n,vector<int>(n,INT_MAX/2));
        //-1 means no edge
        for(int i=0;i<n;i++)
        matrix[i][i]=0;
        for(auto it:edges)
        {
            if(it[2]>threshold)
            continue;
            matrix[it[0]][it[1]]=it[2];
            matrix[it[1]][it[0]]=it[2];
        }
        //now relaxation for every node
        for(int k=0;k<n;k++)
        {
            //from every edges to every edge through i
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][k]+matrix[k][j]<=threshold)
                    {
                        matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                    }
                }
            }
        }
        //matrix is ready
        //finally check
        int mincities=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                //cout<<matrix[i][j]<<" ";
                if(matrix[i][j]!=INT_MAX/2)
                count++;
            }
            //cout<<"\n";
            if(count<=mincities)
            {
                ans=i;
                mincities=count;
            }
        }
        return ans;
    }
};