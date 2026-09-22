/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1ll});
        TreeNode* current;
        //int idx;
        long long maxi=-1;
        while(!q.empty())
        {
            int siz=q.size();
            maxi=max(maxi,q.back().second-q.front().second+1);
            while(siz--)
            {
                auto [current,idx]=q.front();
                q.pop();
                if(current->left) 
                {
                    if(2*idx>=1e10)
                    q.push({current->left,0});
                    else
                    q.push({current->left,2*idx});}
                if(current->right){
                    if(2*idx+1ll>=1e10)
                    q.push({current->right,1});
                    else
                    q.push({current->right,2*idx+1ll});}
            }
            
        }
        return maxi;
    }
};