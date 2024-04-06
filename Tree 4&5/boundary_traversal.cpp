class Solution {
public:
    void leftmostnode(Node *root,vector<int> &res)
    {
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL) return ;
        res.push_back(root->data);
        if(root->left!=NULL)
        {
            leftmostnode(root->left,res);
        }
        else
        {
            leftmostnode(root->right,res);
        }
    }
    void leafnode(Node *root,vector<int> &res)
    {
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL)
        {
            res.push_back(root->data);
            return ;
        }
        leafnode(root->left,res);
        leafnode(root->right,res);
    }
    void rightmostnode(Node *root,vector<int> &res)
    {
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL) return ;
        if(root->right!=NULL)
        {
            rightmostnode(root->right,res);
        }
        else
        {
            rightmostnode(root->left,res);
        }
        res.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        if(root==NULL) return {};
        vector<int> res;
        res.push_back(root->data);
        leftmostnode(root->left,res);
        leafnode(root->left,res);
        leafnode(root->right,res);
        rightmostnode(root->right,res);
        return res;
    }
};