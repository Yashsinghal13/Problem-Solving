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
    void helper(TreeNode *root,int targetSum,vector<vector<int>> &res,vector<int>k)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL && targetSum-root->val==0)
        {
            k.push_back(root->val);
            res.push_back(k);
            return;
        }
        if(root->left==NULL && root->right==NULL && targetSum-root->val!=0)
        {
            return ;
        }
        targetSum-=root->val;
        k.push_back(root->val);
        helper(root->left,targetSum,res,k);
        helper(root->right,targetSum,res,k);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> k;
        helper(root,targetSum,res,k); 
        return res;       
    }
};