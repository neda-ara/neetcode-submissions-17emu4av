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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }

        unordered_map<TreeNode*,pair<int,int>> mp;
        mp[nullptr] = {0,0};

        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode* node = stk.top();

            if(node->left && !mp.count(node->left)) {
                stk.push(node->left);
            } else if(node->right && !mp.count(node->right)) {
                stk.push(node->right);
            } else {
                node = stk.top();
                stk.pop();

                auto[lh,ld] = mp[node->left];
                auto[rh,rd] = mp[node->right];

                int height = 1 + max(lh,rh);
                int diameter = max(lh+rh,max(ld,rd));
                mp[node] = {height,diameter};
            }
        }

        return mp[root].second;
    }
};
