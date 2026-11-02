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
        string serialized_root = serialize(root);
        string serialized_subroot = serialize(subRoot);

        string combined = serialized_subroot + '|' + serialized_root;

        vector<int> z_values = z_function_optimized(combined);
        int sub_len = serialized_subroot.length();

        for(int i=sub_len+1; i<combined.length(); i++) {
            if(z_values[i] == sub_len) {
                return true;
            }
        }
        return false;
    }

    string serialize(TreeNode* root) {
        string res;
        serialize(root,res);
        return res;
    }

private:
    void serialize(TreeNode* root, string& res) {
        if(!root) {
            res += "$#";
            return;
        }

        res += "$" + to_string(root->val);
        serialize(root->left,res);
        serialize(root->right,res);
    }

    vector<int> z_function_easy(string s) {
        int n = s.length();
        vector<int> z(n,0); 

        for(int i=0; i<n; i++) {
            while(i+z[i] < n && s[z[i]] == s[i+z[i]]) {
                z[i]++;
            }
        }

        return z;
    }

    vector<int> z_function_optimized(string s) {
        int n = s.length(), l = 0, r = 0;
        vector<int> z(n,0); 

        for(int i=0; i<n; i++) {
            if(i <= r) {
                z[i] = min(r-i+1,z[i-l]);
            }
            while(i+z[i] < n && s[z[i]] == s[i+z[i]]) {
                z[i]++;
            }
            if(i+z[i]-1 > r) {
                l = i;
                r = i+z[i]-1;
            }
        }

        return z;
    }
};
