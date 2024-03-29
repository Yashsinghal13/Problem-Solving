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
    int maxdepth(TreeNode *root)
    {
        if(root==NULL) return 0;
        int left=1+maxdepth(root->left);
        int right=1+maxdepth(root->right);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return NULL;
        int option1=diameterOfBinaryTree(root->left);
        int option2=diameterOfBinaryTree(root->right);
        int height=maxdepth(root->left)+maxdepth(root->right);
        return max(height,max(option1,option2));
    }
};