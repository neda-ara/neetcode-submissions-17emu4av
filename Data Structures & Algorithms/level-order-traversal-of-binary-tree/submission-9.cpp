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
        vector<vector<int>> traversed_nodes;
        if (!root) {
            return traversed_nodes;
        }
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});

        while (!stk.empty()) {
            auto [node, depth] = stk.top();
            stk.pop();

            if (depth == traversed_nodes.size()) {
                traversed_nodes.push_back({});
            }
            traversed_nodes[depth].push_back(node->val);

            if (node->right) {
                stk.push({node->right, depth + 1});
            }
            if (node->left) {
                stk.push({node->left, depth + 1});
            }
        }

        return traversed_nodes;
    }
};
