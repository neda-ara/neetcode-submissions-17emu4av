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
        if (!root) {
            return 0;
        }

        stack<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});

        int good_nodes = 0;

        while(!q.empty()) {
            auto [node, max_val] = q.top();
            q.pop();

            if(node->val >= max_val) {
                good_nodes++;
            }
            if(node->left) {
                q.push({node->left, max(node->val,max_val)});
            }
            if(node->right) {
                q.push({node->right, max(node->val,max_val)});
            }
        }
        return good_nodes;
    }
};
