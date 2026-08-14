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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*,TreeNode*>> stk;
        stk.push({p,q});

        while(!stk.empty()) {
            auto [tn1,tn2] = stk.top();
            stk.pop();

            if(!tn1 && !tn2) {
                continue;
            }
            if(!tn1 || !tn2 || tn1->val != tn2->val) {
                return false;
            }
            stk.push({tn1->left,tn2->left});
            stk.push({tn1->right,tn2->right});
        }
        return true;
    }
};
