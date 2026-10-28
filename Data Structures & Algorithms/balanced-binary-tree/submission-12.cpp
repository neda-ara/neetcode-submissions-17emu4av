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

        stack<TreeNode*> stk;
        stk.push(root);

        TreeNode* node = root;
        TreeNode* last = nullptr;

        unordered_map<TreeNode*,int> depths;

        while(!stk.empty()) {
            if(node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                if(!node->right || node->right == last) {
                    stk.pop();
                    int lh = depths[node->left];
                    int rh = depths[node->right];
                    if(abs(lh-rh) > 1) {
                        return false;
                    }
                    depths[node] = 1 + max(lh,rh);
                    last = node;
                    node = nullptr;
                } else {
                    node = node->right;
                }
            }
        }
        return true;
    }
};
