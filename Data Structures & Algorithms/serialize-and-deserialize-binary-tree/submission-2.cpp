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
        vector<string> vals;
        dfsSerialize(root,vals);
        cout<< "Serialzed: " << join(vals, ',') << endl;
        return join(vals, ',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return dfsDeSerialize(vals,i);
    }

private:
    void dfsSerialize(TreeNode* node, vector<string>& vals) {
        if(!node) {
            vals.push_back("N");
            return;
        }
        vals.push_back(to_string(node->val));
        dfsSerialize(node->left,vals);
        dfsSerialize(node->right,vals);
    }

    string join(vector<string>& vals, const char& delim) {
        ostringstream s;

        for(const auto& val : vals) {
            if(&val != &vals[0]) {
                s << delim;
            }
            s << val;
        }
        return s.str();
    }

    TreeNode* dfsDeSerialize(vector<string>& vals, int& i) {
        if(vals[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeSerialize(vals,i);
        node->right = dfsDeSerialize(vals,i);
        return node;
    }

    vector<string> split (string data, const char& delim) {
        stringstream ss(data);
        string item;
        vector<string> arr;

        while(getline(ss,item,delim)) {
            arr.push_back(item);
        }
        return arr;
    }
};
