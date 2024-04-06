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
    TreeNode *createTreeFromPreorder(vector<int> &preorder,vector<int>&inorder,int &preorderindex,int inorderstart,int inorderend,map<int,int> &m)
    {
        if(preorderindex>=preorder.size() || inorderstart>inorderend)
        {
            return NULL;
        }
        int ele=preorder[preorderindex];
        preorderindex++;
        int position=m[ele];
        TreeNode *root=new TreeNode(ele);
        root->left=createTreeFromPreorder(preorder,inorder,preorderindex,inorderstart,position-1,m);
        root->right=createTreeFromPreorder(preorder,inorder,preorderindex,position+1,inorderend,m);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        map<int,int> m;
        int preorderindex=0;
        int inorderstart=0,inorderend=preorder.size()-1;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        TreeNode *root=createTreeFromPreorder(preorder,inorder,preorderindex,inorderstart,inorderend,m);
        return root;
    }
};