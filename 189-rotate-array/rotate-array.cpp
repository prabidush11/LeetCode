class Solution {
public:
    void reverse_array(vector<int>& arr, int start,int end)
    {
        int len=end-start+1;
        for(int i=0;i<len/2;i++)
        {
            swap(arr[start+i],arr[end-i]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse_array(nums,0,nums.size()-1);
        reverse_array(nums,0,k-1);
        reverse_array(nums,k,nums.size()-1);
    }
};