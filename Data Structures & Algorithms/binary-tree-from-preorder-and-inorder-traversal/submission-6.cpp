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
    int pre_idx = 0;
    unordered_map<int,int> idx;

private:
    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        if(l > r) {
            return nullptr;
        }
        int root_val = preorder[pre_idx++];
        TreeNode* root = new TreeNode(root_val);
        int mid = idx[root_val];
        root->left = dfs(preorder,l,mid-1);
        root->right = dfs(preorder,mid+1,r);
        return root;
    } 

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        for(int i=0; i<n; i++) {
            idx[inorder[i]] = i;
        }

        return dfs(preorder,0,n-1);
    }
};
