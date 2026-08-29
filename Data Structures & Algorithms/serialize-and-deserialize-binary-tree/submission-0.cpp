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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root,res);
        return join(res,',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return dfsDeSerialize(vals,i);
    }

private:
    void dfsSerialize(TreeNode* root, vector<string>& res) {
        if(!root) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(root->val));
        dfsSerialize(root->left,res);
        dfsSerialize(root->right,res);
    }

    TreeNode* dfsDeSerialize(vector<string>& vals, int& i) {
        if(vals[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(vals[i]));
        i++;

        root->left = dfsDeSerialize(vals,i);
        root->right = dfsDeSerialize(vals,i);
        return root;
    }

    string join (const vector<string>& v, const char& delimiter) {
        ostringstream s;

        for(const auto& i : v) {
            if(&i != &v[0]) {
                s << delimiter;
            }
            s << i;
        }
        return s.str();
    }

    vector<string> split(const string& s, char delimiter) {
        vector<string> elems;
        stringstream ss(s);
        string item;

        while(getline(ss,item,delimiter)) {
            elems.push_back(item);
        }

        return elems;
    }
};
