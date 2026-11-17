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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* head = new TreeNode(0);
        TreeNode* curr = head;

        int pre_idx = 0, in_idx = 0, n = preorder.size();

        while(pre_idx < n && in_idx < n) {
            curr->right = new TreeNode(preorder[pre_idx], nullptr, curr->right);
            curr = curr->right;
            pre_idx++;

            while(pre_idx < n && curr->val != inorder[in_idx]) {
                curr->left = new TreeNode(preorder[pre_idx], nullptr, curr);
                curr = curr->left;
                pre_idx++;
            }
            in_idx++;

            while(curr->right && in_idx < n && curr->right->val == inorder[in_idx]) {
                TreeNode* prev = curr->right;
                curr->right = nullptr;
                curr = prev;
                in_idx++;
            }
        }
        return head->right;
    }
};
