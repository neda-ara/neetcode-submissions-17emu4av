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
        vector<vector<int>> res;
        dfs(root,0,res);
        return res;
    }

private: 
    void dfs(TreeNode* root, int depth, vector<vector<int>>& res) {
        if(!root) {
            return;
        }

        if(res.size() == depth) {
            res.push_back(vector<int>());
        }

        res[depth].push_back(root->val);
        dfs(root->left,depth+1,res);
        dfs(root->right,depth+1,res);
    }
};
