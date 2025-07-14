class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(mini>arr[i])
            mini=arr[i];
        }
        return mini;
    }
};