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

        int depth = 0;

        while(!stk.empty()) {
            auto [node,depthToThisNode] = stk.top();
            stk.pop();
            depth = max(depth,depthToThisNode);
            
            if(node->left) {
                stk.push({node->left,depthToThisNode+1});
            }
            if(node->right) {
                stk.push({node->right,depthToThisNode+1});
            }
        }

        return depth;
    }
};
