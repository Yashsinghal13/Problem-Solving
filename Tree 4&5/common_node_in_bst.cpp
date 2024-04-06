class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
    void traverseTree1(Node *root1,Node *root2,vector<int> &res)
    {
        if(root1==NULL) return;
        int ele=root1->data;
        traverse(root2,ele,res);
        traverseTree1(root1->left,root2,res);
        traverseTree1(root1->right,root2,res);
        return ;
    }
    void traverse(Node *root2,int ele,vector<int> &res)
    {
        if(root2==NULL) return ;
        if(root2->data==ele)
        {
            res.push_back(ele);
            return ;
        }
        if(root2->data>ele)
        {
            traverse(root2->left,ele,res);
        }
        if(root2->data<ele)
        {
            traverse(root2->right,ele,res);
        }
        
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int> res;
     traverseTree1(root1,root2,res);
     sort(res.begin(),res.end());
     return res;
     
    }
};