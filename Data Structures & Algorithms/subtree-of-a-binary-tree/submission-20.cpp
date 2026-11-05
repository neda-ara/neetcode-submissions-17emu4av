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

        string root_serialized = serialize(root);
        string subroot_serialized = serialize(subRoot);

        string combined = subroot_serialized + "|" + root_serialized;
        int subroot_len = subroot_serialized.length();

        vector<int> z_values = z_function_optimized(combined);

        for(int z_val : z_values) {
            if(z_val == subroot_len) {
                return true;
            }
        }

        return false;
    }

private:
    string serialize(TreeNode* node) {
        string serialized_str;
        serialize(node,serialized_str);
        return serialized_str;
    }

    void serialize(TreeNode* node, string& serialized_str) {
        if(!node) {
            serialized_str += "$#";
            return;
        }

        serialized_str += "$" + to_string(node->val);
        serialize(node->left,serialized_str);
        serialize(node->right,serialized_str);
    }

    //"abc|ddhabcdefido"

    vector<int> z_function_easy(string& s) {
        int n = s.length();
        vector<int> z(n,0);
        
        for(int i=1; i<n; i++) {
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
        }

        return z;
    }

    vector<int> z_function_optimized(string& s) {
        int n = s.length(), l = 0, r = 0;
        vector<int> z(n,0);
        
        for(int i=1; i<n; i++) {
            if(i <= r) {
                z[i] = min(r-i+1,z[i-l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i+z[i]-1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;
    }
};
