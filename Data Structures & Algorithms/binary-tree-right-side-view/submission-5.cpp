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
        vector<int> res;
        queue<TreeNode*> q;
        if(root) {
            q.push(root);
        }

        while(!q.empty()) {
            TreeNode* rightSide = q.front();
            int len = q.size();

            if(rightSide) {
                res.push_back(rightSide->val);
            }

            for(int i=0; i<len; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->right) {
                    q.push(node->right);
                }
                if(node->left) {
                    q.push(node->left);
                }
            }
        }

        return res;
    }
};
