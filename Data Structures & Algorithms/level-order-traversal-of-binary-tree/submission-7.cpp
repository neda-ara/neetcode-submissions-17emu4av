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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_nodes;
        if(!root) {
            return level_nodes;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> nodes;
            int prevLevelSize = q.size();

            for(int i=0; i<prevLevelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                nodes.push_back(node->val);
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            if(!nodes.empty()) {
                level_nodes.push_back(nodes);
            }
        }
        return level_nodes;
    }
};
