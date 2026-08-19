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

        int depthMax = 0;

        while(!stk.empty()) {
            auto [node,depth] = stk.top();
            stk.pop();

            if(node) {
                depthMax = max(depthMax,depth);
                stk.push({node->left,depth+1});
                stk.push({node->right,depth+1});
            }
        }
        return depthMax;
    }
};
