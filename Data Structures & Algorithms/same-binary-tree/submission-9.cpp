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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        }

        queue<pair<TreeNode*,TreeNode*>> que;
        que.push({p,q});

        while(!que.empty()) {
            int size = que.size();
            for(int i=0; i<size; i++) {
                auto [n1,n2] = que.front();
                que.pop();

                if(!n1 && !n2) {
                    continue;
                }
                if(!n1 || !n2 || n1->val != n2->val) {
                    return false;
                }

                que.push({n1->left,n2->left});
                que.push({n1->right,n2->right});
            }
        }
        return true;
    }
};
