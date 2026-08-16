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
        vector<int> result;
        queue<TreeNode*> q;

        if(root) {
            q.push(root);
        }

        while(!q.empty()) {
            int size = q.size();
            TreeNode* rightSide = nullptr;

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node) {
                    if(i == 0) {
                        rightSide = node;
                    }       
                    if(node->right) {
                        q.push(node->right);
                    }
                    if(node->left) {
                        q.push(node->left);
                    }
                }
            }
            if(rightSide) {
                result.push_back(rightSide->val);
            }
        }

        return result;
    }
};
