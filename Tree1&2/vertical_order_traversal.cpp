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
    map<pair<int, int>, vector<int>> mp;
    void helper(TreeNode* root, int m, int n) {
        if(root) {
            mp[{n, m}].push_back(root->val);
            helper(root->left, m + 1, n - 1);
            helper(root->right, m + 1, n + 1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root, 0, 0);
        vector<vector<int>> ans;
        int curr_val = INT_MIN;
        int size = 0;
        for(auto val : mp) {
            sort(val.second.begin(), val.second.end());
            if(val.first.first == curr_val) {
                ans[size - 1].insert(ans[size - 1].end(), val.second.begin(), val.second.end());
            }
            else {
                ans.push_back(val.second);
                curr_val = val.first.first;
                size++;
            }
        }
        return ans;
    }
};