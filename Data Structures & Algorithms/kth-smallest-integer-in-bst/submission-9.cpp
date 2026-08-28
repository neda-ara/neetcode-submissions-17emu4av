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
        int cnt = 0;
        return dfs(root,cnt,k);
    }

private:
    int dfs(TreeNode* node, int& cnt, const int& k) {
        if(!node) {
            return -1;
        }
        int left = dfs(node->left,cnt,k);
        if(left != -1) {
            return left;
        }
        cnt++;
        if(cnt == k) {
            return node->val;
        }
        return dfs(node->right,cnt,k);
    }
};
