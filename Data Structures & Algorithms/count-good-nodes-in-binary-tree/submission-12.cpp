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
    int goodNodes(TreeNode* root) { return dfs(root, root->val); }

    int dfs(TreeNode* node, int max_val_so_far) {
        if (!node) {
            return 0;
        }
        int cnt = node->val >= max_val_so_far ? 1 : 0;
        int new_max = max(max_val_so_far, node->val);

        cnt += dfs(node->left, new_max);
        cnt += dfs(node->right, new_max);
        return cnt;
    }
};
