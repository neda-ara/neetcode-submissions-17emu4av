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
        if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }

        string root_sr = serialize(root);
        string subroot_sr = serialize(subRoot);
        int sub_len = subroot_sr.length();

        string combined = subroot_sr + "|" + root_sr;

        vector<int> z_values = z_function(combined);
        for (int& z_val : z_values) {
            if (z_val == sub_len) {
                return true;
            }
        }

        return false;
    }

   private:
    string serialize(TreeNode* root) {
        string serialized;
        serialize(root, serialized);
        return serialized;
    }

    void serialize(TreeNode* root, string& serialized) {
        if (!root) {
            serialized += "$#";
            return;
        }
        serialized += "$" + to_string(root->val);
        serialize(root->left, serialized);
        serialize(root->right, serialized);
    }

    vector<int> z_function(string& s) {
        int n = s.length();
        vector<int> z(n, 0);

        for (int i = 1; i < n; i++) {
            while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
                z[i]++;
            }
        }

        return z;
    }
};
