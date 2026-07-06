class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //vector<int>&remaining(numbers.size());
        int n=numbers.size();
        unordered_map<int,int>rem;
        int remn;
        for(int i=0;i<n;i++)
        {
            remn=target-numbers[i];
            if(rem.find(numbers[i])!=rem.end())
            {
                return {rem[numbers[i]] + 1, i + 1};
            }
            else
            rem[remn]=i;
        }
        return {};
    }
};