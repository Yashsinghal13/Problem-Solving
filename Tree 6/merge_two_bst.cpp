class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void InorderTraversal(Node *root,vector<int> &inorder)
    {
        if(root==NULL) return ;
        InorderTraversal(root->left,inorder);
        inorder.push_back(root->data);
        InorderTraversal(root->right,inorder);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> inorder1;
       vector<int> inorder2;
       InorderTraversal(root1,inorder1);
       InorderTraversal(root2,inorder2);
       int n=inorder1.size(),m=inorder2.size();
       vector<int> mergeBst(n+m,0);
       int i=n-1,j=m-1,k=n+m-1;
       while(i>=0 && j>=0)
       {
           if(inorder1[i]<=inorder2[j])
           {
               mergeBst[k--]=inorder2[j--];
               
           }
           else
            {
                mergeBst[k--]=inorder1[i--];
            }
       }
       while(i>=0)
       {
           mergeBst[k--]=inorder1[i--];
       }
       while(j>=0)
       {
           mergeBst[k--]=inorder2[j--];
       }
       return mergeBst;
    }
};