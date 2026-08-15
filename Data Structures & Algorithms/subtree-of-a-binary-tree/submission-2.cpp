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

    vector<int> z_function_optimal(string s) {
        int l = 0, r = 0, n = s.length();
        vector<int> z(n);
        
        for(int i=1; i<n; i++) {
            // If i is inside the current Z-box [l, r], reuse the
            // previously computed match instead of starting from 0.
            if (i <= r) {
                z[i] = min(r-i+1,z[i-l]);
            }
            // Try to extend the known match by comparing new characters.
            while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
                z[i]++;
            }
            // If this match extends farther right, make it the new Z-box.
            if(i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string serialized_root = serialize(root);
        string serialized_subRoot = serialize(subRoot);
        string combined = serialized_subRoot + "|" + serialized_root;

        vector<int> z_vals = z_function_optimal(combined);
        int sub_len = serialized_subRoot.length();

        for(int i = sub_len + 1; i < combined.length(); i++) {
            if(z_vals[i] == sub_len) {
                return true;
            }
        }

        return false;
    }
};
