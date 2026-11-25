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
        if(!root) {
            return true;
        }
        return dfs(root,LONG_MIN,LONG_MAX);
    }

    bool dfs(TreeNode* root, long minn, long maxx) {
        if(!root) {
            return true;
        }
        if(root->val >= maxx || root->val <= minn) {
            return false;
        }
        return dfs(root->left,minn,root->val) && dfs(root->right,root->val,maxx);
    }
};
