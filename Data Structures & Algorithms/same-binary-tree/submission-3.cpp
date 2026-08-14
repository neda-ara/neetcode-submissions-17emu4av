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

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q); 

        while(!q1.empty() && !q2.empty()) {
            TreeNode* tn1 = q1.front();
            q1.pop();
            TreeNode* tn2 = q2.front();
            q2.pop();

            if(!tn1 && !tn2) {
                continue;
            }
            if(!tn1 || !tn2 || tn1->val != tn2->val) {
                return false;
            }
            q1.push(tn1->left);
            q1.push(tn1->right);
            q2.push(tn2->left);
            q2.push(tn2->right);
        }
        return q1.empty() && q2.empty();
    }
};
