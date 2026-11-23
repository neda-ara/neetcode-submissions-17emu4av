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
        unordered_map<TreeNode*,int> depths;
        depths[nullptr] = 0;

        stack<TreeNode*> stk;
        TreeNode* curr = root;
        TreeNode* last = nullptr;

        while(!stk.empty() || curr) {
            if(curr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                curr = stk.top();

                if(!curr->right || last == curr->right) {
                    stk.pop();
                    int lh = depths[curr->left];
                    int rh = depths[curr->right];

                    if(abs(lh-rh) > 1) {
                        return false;
                    }
                    depths[curr] = 1 + max(lh,rh);
                    last = curr;
                    curr = nullptr;
                } else {
                    curr = curr->right;
                }
            }
        }
        return true;
    }
};
