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
        vector<int> right_view_nodes;
        if (!root) {
            return right_view_nodes;
        }

        dfs(root, right_view_nodes, 0);
        return right_view_nodes;
    }

    void dfs(TreeNode* root, vector<int>& right_view_nodes, int depth) {
        if (!root) {
            return;
        }
        if (depth == right_view_nodes.size()) {
            right_view_nodes.push_back(root->val);
        }

        dfs(root->right, right_view_nodes, depth + 1);
        dfs(root->left, right_view_nodes, depth + 1);
    }
};
