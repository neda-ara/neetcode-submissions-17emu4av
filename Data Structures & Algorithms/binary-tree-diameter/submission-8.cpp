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
        if (!root) {
            return 0;
        }

        int lh = depth(root->left), rh = depth(root->right);
        int diameter = lh + rh;

        int subTreeDiameter =
            max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));

        return max(diameter, subTreeDiameter);
    }

    int depth(TreeNode* node) {
        if(!node) {
            return 0;
        }
        return 1 + max(depth(node->left),depth(node->right));
    }

};
