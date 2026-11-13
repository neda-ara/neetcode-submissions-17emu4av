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
        if (!root) {
            return true;
        }

        unordered_map<TreeNode*, int> mpp;
        mpp[nullptr] = 0;

        stack<TreeNode*> stk;
        TreeNode* node = root;
        TreeNode* last = nullptr;

        while (!stk.empty() || node) {
            if (node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                if (!node->right || last == node->right) {
                    stk.pop();
                    int lh = mpp[node->left];
                    int rh = mpp[node->right];
                    if (abs(lh - rh) > 1) {
                        return false;
                    }
                    mpp[node] = 1 + max(lh, rh);
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
