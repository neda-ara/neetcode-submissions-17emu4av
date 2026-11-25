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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        dfs(root, ans, k);
        return ans;
    }

    void dfs(TreeNode* root, int& ans, int& k) {
        if (!root) {
            return;
        }
        dfs(root->left, ans, k);
        if (k == 0) {
            return;
        }

        k--;
        if(k == 0) {
            ans = root->val;
            return;
        }

        dfs(root->right, ans, k);
    }
};
