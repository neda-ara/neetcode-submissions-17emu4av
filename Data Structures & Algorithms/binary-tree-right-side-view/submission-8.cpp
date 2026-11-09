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
        dfs(root, 0, rightViewNodes);
        return rightViewNodes;
    }

    void dfs(TreeNode* node, int depth, vector<int>& rightViewNodes) {
        if(!node) {
            return;
        }

        if(depth == rightViewNodes.size()) {
            rightViewNodes.push_back(node->val);
        }

        dfs(node->right, depth + 1, rightViewNodes);
        dfs(node->left, depth + 1, rightViewNodes);
    }
};
