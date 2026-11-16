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
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        int count = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [node, maxVal] = q.front();
                q.pop();

                if (node->val >= maxVal) {
                    count++;
                }

                maxVal = max(maxVal, node->val);

                if (node->left) {
                    q.push({node->left, maxVal});
                }
                if (node->right) {
                    q.push({node->right, maxVal});
                }
            }
        }

        return count;
    }
};
