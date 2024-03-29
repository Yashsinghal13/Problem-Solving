//finding height of a tree using level order traversal
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int height=1;
        queue<TreeNode *>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            if(node==NULL)
            {
                if(!q.empty())
                {
                    height++;
                    q.push(NULL);
                }
            }
            else
            {
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);  
            }
        } 
        return height;
    }
};