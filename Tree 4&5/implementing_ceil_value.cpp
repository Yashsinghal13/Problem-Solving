// Function to return the ceil of given number in BST.
int ans=-1;
int helper(Node* root, int input) {
    if(root==NULL) return -1;
    if(root->data>=input)
    {
        ans=(ans==-1)?root->data:min(root->data,ans);
    }
    helper(root->left,input);
    helper(root->right,input);
    return ans ;
}
int findCeil(Node* root, int input) {
    ans = -1;
   return helper(root, input);
    // Your code here
}
