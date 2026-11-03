class Solution {
public:
    int minMoves(vector<int>& nums) {
        //find max element
        int sum=0;
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        return maxi*n-sum;
    }
};