class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int left=0,right=n-1;
        int maxi=0;
        while(left<right)
        {
            maxi=max(maxi,(right-left)*min(heights[left],heights[right]));
            if(heights[left]<heights[right])
            left++;
            else right--;
        }
        return maxi;
    }
};