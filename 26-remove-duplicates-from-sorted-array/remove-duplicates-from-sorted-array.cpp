class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int max=arr[0];
        int count=1;
        int current=1, n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
                count++;
                arr[current++]=arr[i];
            }
        }
        return count;
    }
};