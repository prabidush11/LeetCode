class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx=0,current=0,n=nums.size();
        for(idx=0;idx<n;idx++)
        {
            if(nums[idx]!=0)
            {
                nums[current]=nums[idx];
                current++;
            }
            //idx++;
        }
        for(;current<n;current++)
        nums[current]=0;
    }
};