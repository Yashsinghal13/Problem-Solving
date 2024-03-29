vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(root==NULL) return {};
        vector<int> leftview;
        vector<vector<int>> res;
        queue<BinaryTreeNode<int>*>q;
        q.push(root);
        q.push(NULL);
        vector<int> k;
        while(!q.empty())
        {
            BinaryTreeNode<int>* node=q.front();
            q.pop();
            if(node==NULL)
            {
                if(!q.empty())
                {
                    res.push_back(k);
                    q.push(NULL);
                    k.clear();
                }
            }
            else
            {
                k.push_back(node->data);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
        }
        res.push_back(k);
        for(int i=0;i<res.size();i++)
        {
            leftview.push_back(res[i][0]);
        }
        return leftview;
}