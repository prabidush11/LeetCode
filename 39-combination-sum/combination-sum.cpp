class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>>&ans,vector<int>& temp,int&target,int &sum,int ptr)
    {
        //if(ptr==candidates)
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        if(sum>target)
        return;
        for (int i = ptr; i < candidates.size(); i++) {
    sum += candidates[i];
    temp.push_back(candidates[i]);

    solve(candidates, ans, temp, target, sum, i);

    sum -= candidates[i];
    temp.pop_back();
}
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> temp;
        //vector<int> memo(candidates.size());
        int n=candidates.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            solve(candidates,ans,temp,target,sum,i);
            sum-=candidates[i];
            temp.pop_back();
        }
        return ans;
    }
};