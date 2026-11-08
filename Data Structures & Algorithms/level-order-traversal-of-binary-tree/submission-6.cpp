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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }

        vector<vector<int>> level_nodes;
        dfs(root, 0, level_nodes);
        return level_nodes;
    }

    void dfs(TreeNode* node, int depth, vector<vector<int>>& level_nodes) {
        if(!node) {
            return;
        }
        if(depth == level_nodes.size()) {
            level_nodes.push_back({});
        }

        level_nodes[depth].push_back(node->val);
        dfs(node->left, depth+1, level_nodes);
        dfs(node->right, depth+1, level_nodes);
    }
};
