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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) {
            return true;
        }
        if(!root) {
            return false;
        }
        string serializedRoot = serialize(root);
        string serializedSubRoot = serialize(subRoot);
        string combined = serializedSubRoot + "|" + serializedRoot;

        vector<int> z_values = z_function_optimal(combined);
        int sub_len = serializedSubRoot.length();

        for(int i=sub_len+1; i<combined.length(); i++) {
            if(z_values[i] == sub_len) {
                return true;
            }
        }
        return false;
    }

private: 
    string serialize(TreeNode* root) {
        string serializedStr;
        if(!root) {
            return "$#";
        }
        
        return "$" + to_string(root->val) + 
        serialize(root->left) + serialize(root->right);
    }

    vector<int> z_function_easy(string s) {
        int len = s.length();
        vector<int> z(len);

        for(int i=1; i<len; i++) {
            while(i+z[i] < len && s[z[i]] == s[i+z[i]]) {
                z[i]++;
            }
        }

        return z;
    }

    vector<int> z_function_optimal(string s) {
        int l = 0, r = 0, n = s.length();
        vector<int> z(n);

        for(int i=1; i<n; i++) {
            if(i <= r) {
                z[i] = min(i+z[i]-1,z[i-l]);
            }
            while(i+z[i] < n && s[z[i]] == s[z[i]+i]) {
                z[i]++;
            }
            if(i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }
};
