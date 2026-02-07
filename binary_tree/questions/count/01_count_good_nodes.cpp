class Solution {
public:
    void solve(TreeNode* root, int &ans, int &greatest) {
        // Base case: reached beyond a leaf
        if (root == nullptr) return;

        /*
            A node is GOOD if on the path from root to this node
            there is NO value greater than it.

            'greatest' stores the maximum value seen so far
            on the path from the root to the parent of this node.

            If current value >= greatest,
            then no previous node is greater than current → GOOD node
        */
        if (root->val >= greatest) {
            ans++;   // count this node as good
        }

        /*
            Save current greatest before going deeper.
            This is needed because left and right subtrees
            must be evaluated independently.
        */
        int temp = greatest;

        // Update greatest if current node has a larger value
        if (root->val > greatest) {
            greatest = root->val;
        }

        // Explore left subtree with updated maximum
        solve(root->left, ans, greatest);

        // Explore right subtree with updated maximum
        solve(root->right, ans, greatest);

        // Restore greatest when backtracking to parent
        greatest = temp;
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int ans = 0;

        // Root is the first node on every path,
        // so the maximum value seen so far starts as root->val
        int greatest = root->val;

        // Start DFS traversal
        solve(root, ans, greatest);

        return ans;
    }
};
