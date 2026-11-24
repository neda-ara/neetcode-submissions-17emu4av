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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_nodes;
        if (!root) {
            return right_nodes;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            TreeNode* rightNode = nullptr;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (!rightNode) {
                    rightNode = node;
                }
                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }
            }
            if(rightNode) {
                right_nodes.push_back(rightNode->val);
            }
        }

        return right_nodes;
    }
};
