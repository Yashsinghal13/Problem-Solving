/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool path(TreeNode *root, int B,vector<int>&res){
    if(root==NULL)return false;
    res.push_back(root->val);
    if(root->val==B || path(root->left,B,res) || path(root->right,B,res)){   
        return true;}
    res.pop_back();
    return false;   
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    path(A,B,res);
    return res;
}
