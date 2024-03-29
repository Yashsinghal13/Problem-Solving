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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL && targetSum-root->val==0)
        {
            return true;
        }
        if(root->left==NULL && root->right==NULL && targetSum-root->val!=0)
        {
            return false;
        }
        targetSum-=root->val;
        bool option1=hasPathSum(root->left,targetSum);
        bool option2=hasPathSum(root->right,targetSum);
        return option1 || option2;
    }
};