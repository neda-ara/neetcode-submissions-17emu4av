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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int nodeDiam = maxHeight(root->left) + maxHeight(root->right);
        int subTreeDiam = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));

        return max(nodeDiam,subTreeDiam);
    }

private:
    int maxHeight(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + max(maxHeight(root->left),maxHeight(root->right));
    }
};
