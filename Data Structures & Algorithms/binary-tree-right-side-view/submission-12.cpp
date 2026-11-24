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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_nodes;
        dfs(root, right_nodes, 0);
        return right_nodes;
    }

    void dfs(TreeNode* node, vector<int>& res, int depth) {
        if (!node) {
            return;
        }
        if (res.size() == depth) {
            res.push_back(node->val);
        }
        dfs(node->right, res, depth + 1);
        dfs(node->left, res, depth + 1);
    }
};
