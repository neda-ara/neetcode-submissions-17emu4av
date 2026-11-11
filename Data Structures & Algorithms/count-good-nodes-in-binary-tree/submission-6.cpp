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
        return dfs(root,INT_MIN);
    }

    int dfs(TreeNode* node, int maxVal) {
        if(!node) {
            return 0;
        }
        int res = 0;
        if(node->val >= maxVal) {
            res++;
        }
        maxVal = max(node->val,maxVal);
        res += dfs(node->left, maxVal);
        res += dfs(node->right, maxVal);
        return res;
    }
};
