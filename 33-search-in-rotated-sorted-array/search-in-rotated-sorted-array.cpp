class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        if(n==1)
        {
            return arr[0]==target?0:-1;
        }
        if(n==2)
        {
            if(arr[0]==target) return 0;
            else if(arr[1]==target)
            return 1;
            return -1;
        }
        if(n==3)
        {
            if(arr[0]==target) return 0;
            else if(arr[1]==target)
            return 1;
            else if(arr[2]==target) return 2;
            return -1;
        }
        int low=0,high=n-1;
        int mid,tb=-1;
        while(low<high)
        {
            mid=(low+high)/2;
            if(arr[mid]>arr[mid+1])
            {
                tb=mid;
                break;
            }
            else if(arr[mid]<arr[mid-1])
            {
                tb=mid-1;
                break;
            }
            else
            {
                if(arr[0]>arr[mid-1])
                high=mid-1;
                else low=mid+1;
            }
        }
        cout<<tb<<endl;

        //you got the point to break the array
        //now you have two individual arrays, apply b.s.

        //array1 0-tb
        low=0;high=tb;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]==target) return mid;
            else
            {
                if(arr[mid]>target)
                high=mid-1;
                else low=mid+1;
            }
        }

        low=tb+1;high=n-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]==target) return mid;
            else
            {
                if(arr[mid]>target)
                high=mid-1;
                else low=mid+1;
            }
        }
        return -1;
    }
};