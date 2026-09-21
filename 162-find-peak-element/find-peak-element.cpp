class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        //lets apply binary search
        //lets not apply
        int maxi=nums[0];int maxidx=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                maxidx=i;
            }
        }
        return maxidx;
    }
};