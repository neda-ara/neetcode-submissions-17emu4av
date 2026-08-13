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
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }

private:
    pair<bool,int> dfs(TreeNode* root) {
        if(!root) {
            return {true,0};
        }

        auto [lb,lh] = dfs(root->left);
        auto [rb,rh] = dfs(root->right);

        bool balanced = lb && rb && abs(lh-rh) <= 1;

        int height = 1 + max(lh,rh);
        return {balanced,height};
    }
};
