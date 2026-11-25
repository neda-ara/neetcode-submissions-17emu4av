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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        queue<tuple<TreeNode*, long, long>> q;
        q.push({root, LONG_MIN, LONG_MAX});

        while (!q.empty()) {
            auto [node, lower, upper] = q.front();
            q.pop();

            if (node->val <= lower || node->val >= upper) {
                return false;
            }

            if (node->left) {
                q.push({node->left, lower, node->val});
            }
            if (node->right) {
                q.push({node->right, node->val, upper});
            }
        }

        return true;
    }
};
