class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0,mini=INT_MAX;
        int n=nums.size();
        if(n==1) return 0;
        for(auto it:nums) {sum+=it;mini=min(mini,it);}
        return sum-n*mini;
    }
};