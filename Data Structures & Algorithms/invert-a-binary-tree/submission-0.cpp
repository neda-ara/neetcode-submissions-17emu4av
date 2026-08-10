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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return nullptr;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            TreeNode* node = nodes.front();
            nodes.pop();
            swap(node->left,node->right);
            if(node->left) {
                nodes.push(node->left);
            }
            if(node->right) {
                nodes.push(node->right);
            }
        }
        return root;
    }
};
