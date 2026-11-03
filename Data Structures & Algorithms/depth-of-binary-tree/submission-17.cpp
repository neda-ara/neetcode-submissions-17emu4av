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

        int depth_max = 0;
        stack<pair<TreeNode*,int>> stk;
        stk.push({root,1});

        while(!stk.empty()) {
            auto [node,depth] = stk.top();
            stk.pop();

            depth_max = max(depth_max,depth);

            if(node->left) {
                stk.push({node->left,depth+1});
            }
            if(node->right) {
                stk.push({node->right,depth+1});
            }
        }

        return depth_max;
    }
};
