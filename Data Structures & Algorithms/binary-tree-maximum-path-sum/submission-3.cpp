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
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root,res);
        return res;
    }

private:
    int dfs(TreeNode* node, int& res) {
        if(!node) {
            return 0;
        }

        int left = dfs(node->left,res);
        int right = dfs(node->right,res);

        res = max(res,node->val+left+right);
        return max(0,node->val+max(left,right));
    }
};
