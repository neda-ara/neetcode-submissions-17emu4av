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
        vector<vector<int>> traversed_nodes;
        dfs(root, traversed_nodes, 0);
        return traversed_nodes;
    }

private:
    void dfs(TreeNode* root, vector<vector<int>>& traversed_nodes, int depth) {
        if(!root) {
            return;
        }
        if(traversed_nodes.size() == depth) {
            traversed_nodes.push_back({});
        }
        traversed_nodes[depth].push_back(root->val);
        dfs(root->left, traversed_nodes, depth+1);
        dfs(root->right, traversed_nodes, depth+1);
    }
};
