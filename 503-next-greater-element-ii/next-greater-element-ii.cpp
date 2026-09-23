class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> ans(n,-1);
        //now find the index of the biggest element
        //this could be done earlier too
        //
        int idx=0;
        int maxi=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                idx=i;
            }
        }
        //the max index is i;
        //now use i as pivot and apply the same things
        //apply next greater element from 0 to idx
        st.push(nums[idx]);
        ans[idx]=-1;
        for(int i=idx-1;i>=0;i--)
        {
            //if bigger number arrives
            if(nums[i]>=st.top())
            {
                //pop until big
                while(!st.empty() && st.top()<=nums[i])
                st.pop();
                if(st.empty())
                ans[i]=-1;
                else
                ans[i]=st.top();
                st.push(nums[i]);
            }
            else
            {
                ans[i]=st.top();
                st.push(nums[i]);
            }
        }
        //till here we got the ans from 0 to idx, now find answer for idx+1 to n-1
        //now using the current stack, find the answer from i+1 to n-1;
        for(int i=n-1;i>=idx+1;i--)
        {
            //if bigger number arrives
            if(nums[i]>=st.top())
            {
                //pop until big
                while(!st.empty() && st.top()<=nums[i])
                st.pop();
                if(st.empty())
                ans[i]=-1;
                else
                ans[i]=st.top();
                st.push(nums[i]);
            }
            else
            {
                ans[i]=st.top();
                st.push(nums[i]);
            }
        }
        return ans;
    }
};