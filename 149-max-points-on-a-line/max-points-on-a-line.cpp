class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1) return 1;
        //make the line using two points, then check how many more lie on it
        int maxpoints=0;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //line is
                int x1=points[i][0];
                int x2=points[j][0];
                int y1=points[i][1];
                int y2=points[j][1];
                int count=0;
                for(int k=j+1;k<n;k++)
                {
                    int n1=points[k][0];
                    int n2=points[k][1];
                    bool collinear;

                    if (x1 == x2) {
                    collinear = (n1 == x1);
                    } else {
                    collinear = abs((n2 - y1) -
                    ((double)(y2 - y1) / (x2 - x1)) * (n1 - x1)) < 1e-9;
                    }
                    if(collinear)
                    count++;
                }
                maxpoints=max(maxpoints,count);
            }
        }
        return maxpoints+2;
    }
};