class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long ans=1;
        int count0=0;
        for(auto &it:nums){ 
            if(it)ans*=it;
            else count0++;}
        if(count0==0)
        {    
        for(int i=0;i<nums.size();i++)
        {
           nums[i]=ans/nums[i];
        }
        }
        else if(count0==1)
        {
            for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
           nums[i]=ans;
           else
           nums[i]=0;
        }
        }
        else
        for(int i=0;i<nums.size();i++)
        nums[i]=0;
        return nums;
    }
};