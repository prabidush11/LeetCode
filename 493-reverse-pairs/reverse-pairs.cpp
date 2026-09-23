class Solution {
public:
    int calculate_score(vector<int>&nums,int start,int mid,int end)
    {
        //using two pointers
        //calculate the score
        //both halves are sorted internally
        //and their indexes do no interfere
        //their individual scores are calculated
        //so we need to check for both the sorted halves
        int ptr1=start,ptr2=mid+1;
        int score=0;
        while(ptr1<=mid)
        {
            while(ptr2<=end && nums[ptr1]>2LL*nums[ptr2])
            {
                ptr2++;
            }
            score+=ptr2-(mid+1);
            ptr1++;
        }
        return score;
    }
    int merge(vector<int>&nums,int start,int mid,int end)
    {
        int ptr1=start;
        int ptr2=mid+1;
        //calculate score first;
        //before merging calculate score;
        int score=calculate_score(nums,start,mid,end);
        //score calculated here, now sort the array
        vector<int> temp;
        while(ptr1<=mid && ptr2<=end)
        {
            if(nums[ptr1]<nums[ptr2])
            {
                temp.push_back(nums[ptr1]);
                ptr1++;
            }
            else
            {
                temp.push_back(nums[ptr2]);
                ptr2++;
            }
        }
        while(ptr1<=mid)
        temp.push_back(nums[ptr1++]);
        while(ptr2<=end)
        temp.push_back(nums[ptr2++]);
        //copy temp in nums
        for(int i=0;i<=end-start;i++)
        {
            nums[start+i]=temp[i];
        }
        return score;
    }
    int mergesort(vector<int>&nums,int start,int end)
    {
        if(start>=end) return 0;
        int mid=start+(end-start)/2;
        int score=0;
        score+=mergesort(nums,start,mid);
        score+=mergesort(nums,mid+1,end);
        score+=merge(nums,start,mid,end);
        return score;
    }
    int reversePairs(vector<int>& nums) {
        //mergesort algo
        return mergesort(nums,0,nums.size()-1);
    }
};