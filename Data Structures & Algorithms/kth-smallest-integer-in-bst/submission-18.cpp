class Solution {
   public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        dfs(root, ans, k);
        return ans;
    }

    // In-order traversal (Left -> Node -> Right) visits BST nodes in ascending order.
    // Both 'ans' and 'k' are passed by reference so all recursive calls share the same state.
    void dfs(TreeNode* node, int& ans, int& k) {
        // Base case: reached a null child
        if (!node) {
            return;
        }

        // 1. Search the left subtree first (smaller values)
        dfs(node->left, ans, k);

        // Early exit: if the answer was already found in the left subtree,
        // stop immediately so we don't decrement 'k' again or search right.
        if (k == 0) {
            return;
        }

        // 2. Process the current node: count it as visited
        k--;
        if (k == 0) {
            ans = node->val;  // Found the k-th smallest element
            return;           // Stop searching further
        }

        // 3. Search the right subtree (larger values)
        dfs(node->right, ans, k);
    }
};
