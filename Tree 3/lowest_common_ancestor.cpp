class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p) return p;
        if(root==q) return q;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL && right==NULL) return NULL;
        else if(left!=NULL  && right!=NULL) return root;
        else if(left!=NULL) return left;
        else if(right!=NULL) return right;
        else{
            return root;
        }
        
    }
};