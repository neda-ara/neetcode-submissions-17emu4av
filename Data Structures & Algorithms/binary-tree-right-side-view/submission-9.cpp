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
        vector<int> rightViewNodes;
        if(!root) {
            return rightViewNodes;
        }
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();

            TreeNode* rightViewNode = nullptr;
            for(int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(!rightViewNode) {
                    rightViewNode = node;
                }

                if(node->right) {
                    q.push(node->right);
                }
                if(node->left) {
                    q.push(node->left);
                }
            } 
            rightViewNodes.push_back(rightViewNode->val);
        }
        
        return rightViewNodes;
    }
};
