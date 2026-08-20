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
        if(!root) {
            return true;
        }

        return dfs(root).second;
    }

private:
    pair<int,bool> dfs(TreeNode* node) {
        pair<int,bool> pairs;

        if(!node) {
            return {0,true};
        }

        auto [lh,lb] = dfs(node->left);
        auto [rh,rb] = dfs(node->right);

        bool isBalanced = lb && rb && abs(lh-rh) <= 1;

        return {1 + max(lh,rh),isBalanced};
    }
};
