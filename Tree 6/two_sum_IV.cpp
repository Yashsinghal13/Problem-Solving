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
    bool binarySearch(vector<int>&inorder,int n2,int start,int end)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(inorder[mid]==n2) return true;
            else if(inorder[mid]>n2) end=mid-1;   
            else{start=mid+1;}
        }
        return false;
    }
    void InorderTraversal(TreeNode *root,vector<int> &inorder)
    {
        if(root==NULL) return ;
        InorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        InorderTraversal(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        InorderTraversal(root,inorder);
        if(inorder.size())
        for(int i=0;i<inorder.size();i++)
        {
            int n2=k-inorder[i];
            int start,end;
            if(n2<inorder[i])
            {
                start=0;
                end=i-1;
            }
            else
            {
                start=i+1;
                end=inorder.size()-1;
            }
            bool find=binarySearch(inorder,n2,start,end);
            if(find) return true;
        }
        return false;
    }
};