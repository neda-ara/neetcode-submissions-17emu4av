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
    int preIdx = 0;
    unordered_map<int,int> indices;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inSize = inorder.size();

        for(int i=0; i<inSize; i++) {
            indices[inorder[i]] = i;
        }

        return dfs(preorder,0,inSize-1);
    }

private:
    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        if(l > r) {
            return nullptr;
        }

        int root_val = preorder[preIdx++];
        TreeNode* root = new TreeNode(root_val);

        int mid = indices[root_val];
        root->left = dfs(preorder,l,mid-1);
        root->right = dfs(preorder,mid+1,r);

        return root;
    }
};
