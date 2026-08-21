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
    int goodNodes(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,INT_MIN});

        while(!q.empty()) {
            auto [node,maxSoFarOnPath] = q.front();
            q.pop();

            if(node->val >= maxSoFarOnPath) {
                res++;
            }

            int newMax = max(maxSoFarOnPath,node->val);
            if(node->left) {
                q.push({node->left,newMax});
            }
            if(node->right) {
                q.push({node->right,newMax});
            }
        }

        return res;   
    }
};
