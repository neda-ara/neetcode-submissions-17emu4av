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
    string serialize(TreeNode* root) {
        if(!root) {
            return "$#";
        }
        return "$" + to_string(root->val) + 
        serialize(root->left) + serialize(root->right);
    }

    vector<int> z_function_easy(string s) {
        int n = s.length();
        vector<int> z(n);

        for(int i=1; i<n; i++) {
            while(i + z[i] < n && s[i+z[i]] == s[z[i]]) {
                z[i]++;
            }
        }

        return z;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string serialized_root = serialize(root);
        string serialized_subRoot = serialize(subRoot);
        string combined = serialized_subRoot + "|" + serialized_root;

        vector<int> z_vals = z_function_easy(combined);
        int sub_len = serialized_subRoot.length();

        for(int i = sub_len + 1; i < combined.length(); i++) {
            if(z_vals[i] == sub_len) {
                return true;
            }
        }

        return false;
    }
};
