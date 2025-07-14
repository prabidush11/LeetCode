class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> Set;
        for(int i=0;i<nums.size();i++)
        {
            if(Set.find(nums[i])!=Set.end())
            return true;
            Set.insert(nums[i]);
        }
        return false;
    }
};