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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        stack<pair<TreeNode*,int>> stk;
        stk.push({root, 1});
        int depth = 0;

        while (!stk.empty()) {
            auto [node, height] = stk.top();
            stk.pop();
            depth = max(height, depth);
            if (node->left) {
                stk.push({node->left, height + 1});
            }
            if (node->right) {
                stk.push({node->right, height + 1});
            }
        }

        return depth;
    }
};
