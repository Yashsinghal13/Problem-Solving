class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> rightview;
        vector<vector<int>> res;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int> k;
        while(!q.empty())
        {
            TreeNode* node=q.front();
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
                k.push_back(node->val);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
        }
        res.push_back(k);
        for(int i=0;i<res.size();i++)
        {
            rightview.push_back(res[i][res[i].size()-1]);
        }
        return rightview;
    }
}; 