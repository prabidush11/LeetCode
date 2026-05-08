class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> nums2(nums.size());
        for(int i=0;i<nums.size();i++)
        nums2[i]={nums[i],i};

        sort(nums2.begin(),nums2.end());

        int first=0,last=nums.size()-1,sum=0;
        while(last>first)
        {
            sum=nums2[first].first+nums2[last].first;
            if(sum==target) return {nums2[first].second,nums2[last].second};
            else if(sum>target) last--;
            else first++;
        }
        return {};
    }
};