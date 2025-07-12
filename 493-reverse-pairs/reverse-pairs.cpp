class Solution {
    int merge(vector<int>&nums,int low,int mid,int high)
    {
        int ptr1=low,ptr2=mid+1;
        int sum=0;
        vector<int> temp;
        for (ptr1 = low; ptr1 <= mid; ptr1++) {
            while (ptr2 <= high && (long long)nums[ptr1] > 2LL * nums[ptr2]) {
                ptr2++;
            }
            sum += (ptr2 - (mid + 1));
        }
        ptr1=low;ptr2=mid+1;
        while(ptr1<=mid && ptr2<=high)
        {
            if(nums[ptr1]<=nums[ptr2])
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
        {
            temp.push_back(nums[ptr1]);
            ptr1++;
        }
        while(ptr2<=high)
        {
            temp.push_back(nums[ptr2]);
            ptr2++;
        }
        for(int i=0;i<high-low+1;i++)
        nums[low+i]=temp[i];
        return sum;

    }
    int mergesort(vector<int>& nums,int low, int high)
    {
        if(low==high)
        return 0;
        int mid=(low+high)/2,sum=0;
        sum+=mergesort(nums,low,mid);
        sum+=mergesort(nums,mid+1,high);
        sum+=merge(nums,low,mid,high);
        return sum;
    }
public:
    int reversePairs(vector<int>& nums) {
        //just do some merge sort
        return mergesort(nums,0,nums.size()-1);
    }
};