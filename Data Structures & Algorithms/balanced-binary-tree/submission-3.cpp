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
        stack<TreeNode*> stk;
        TreeNode* node = root;
        TreeNode* last = nullptr;
        unordered_map<TreeNode*,int> depths;

        while(!stk.empty() || node) {
            if(node) {
                stk.push(node);
                node = node -> left;
            } else {
                node = stk.top();
                if(node->right == nullptr || last == node->right) {
                    stk.pop();
                    int left = depths[node->left];
                    int right = depths[node->right];
                    if(abs(left-right) > 1) {
                        return false;
                    }
                    depths[node] = 1 + max(left,right);
                    last = node;
                    node = nullptr;
                } else {
                    node = node -> right;
                }
            }
        }
        return true;
    }
};
