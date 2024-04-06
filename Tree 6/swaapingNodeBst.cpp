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
//This Solution Ihave Done with Brute Force But I am Trying to do in a constant space.
class Solution {
public:
    void Traversal(TreeNode *root,vector<int> &inorder)
    {
        if(root==NULL) return ;
        Traversal(root->left,inorder);
        inorder.push_back(root->val);
        Traversal(root->right,inorder);
    }
    void swappingNode(TreeNode *root,int node1,int node2)
    {
        if(root==NULL) return ;
        if(root->val==node1)
        {
            root->val=node2;
        }
        else if(root->val==node2)
        {
            root->val=node1;
        }
        swappingNode(root->left,node1,node2);
        swappingNode(root->right,node1,node2);

    }
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        Traversal(root,inorder);
        vector<int> correctBst=inorder;
        sort(correctBst.begin(),correctBst.end());
        int node1,node2;
        int count=0;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]!=correctBst[i] && count==0)
            {
                node1=inorder[i];
                count++;
            }
            else if(inorder[i]!=correctBst[i])
            {
                node2=inorder[i];
                break;
            }
        }
        swappingNode(root,node1,node2);

        
    }
};