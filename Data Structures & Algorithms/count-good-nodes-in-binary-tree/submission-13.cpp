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
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int count = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while (!q.empty()) {
            auto [node, max_so_far] = q.front();
            q.pop();

            if (node->val >= max_so_far) {
                count++;
            }
            int new_max = max(node->val, max_so_far);

            if (node->left) {
                q.push({node->left, new_max});
            }
            if (node->right) {
                q.push({node->right, new_max});
            }
        }

        return count;
    }
};