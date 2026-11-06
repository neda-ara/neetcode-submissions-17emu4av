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
        vector<int> rights;
        dfs(root, 0, rights);
        return rights;
    }

    void dfs(TreeNode* node, int depth, vector<int>& rights) {
        if(!node) {
            return;
        }
        if(rights.size() == depth) {
            rights.push_back(node->val);
        }

        dfs(node->right, depth+1, rights);
        dfs(node->left, depth+1, rights);
    }
};
