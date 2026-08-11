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
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }

        stack<pair<TreeNode*,int>> stk;
        stk.push({root,1});
        int res = 0;

        while(!stk.empty()) {
            pair<TreeNode*,int> curr = stk.top();
            stk.pop();

            TreeNode* node = curr.first;
            int depth = curr.second;

            if(node){
                res = max(res,depth);
                stk.push({node->right,depth+1});
                stk.push({node->left,depth+1});
            }
        }
        return res;
    }
};
