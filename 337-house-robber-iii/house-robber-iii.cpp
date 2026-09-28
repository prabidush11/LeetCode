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
    unordered_map<TreeNode*,int> robb,nrob;
    int solve(TreeNode* node,bool parent)
    {
        //parent->true==parent is robbed
        //parent->false==parent is not robbed
        //base case
        if(!node) return 0;
        if(parent && robb.find(node)!=robb.end())
        return robb[node];
        if(!parent && nrob.find(node)!=nrob.end())
        return nrob[node];
        //choice diagram
        if(parent)
        {
            int left=0,right=0;
            left=solve(node->left,false);
            right=solve(node->right,false);
            return robb[node]=left+right;
        }
        else
        {
            //rob
            int leftrob=0,rightrob=0;
            int leftnrob=0,rightnrob=0;
            leftrob=solve(node->left,true);
            rightrob=solve(node->right,true);
            int robbed=node->val+leftrob+rightrob;
            //dont rob
            leftnrob=solve(node->left,false);
            rightnrob=solve(node->right,false);
            int nrobbed=leftnrob+rightnrob;
            return nrob[node]=max(robbed,nrobbed);
        }
    }
public:
    int rob(TreeNode* root) {
        return solve(root,false);
    }
};