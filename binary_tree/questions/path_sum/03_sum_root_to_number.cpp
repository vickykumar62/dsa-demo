class Solution {
public:
    // A node is a leaf if it has no left and no right child
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    // DFS to build numbers from root to leaf
    void solve(TreeNode* root, int &count, int &ans) {
        // If node is NULL, stop
        if (root == nullptr) return;

        // Add current digit to the number
        // Example: 12 -> 123
        count = (count * 10) + root->val;

        // If leaf node reached, add the formed number to answer
        if (isLeaf(root)) {
            ans += count;
        }

        // Go to left child
        solve(root->left, count, ans);

        // Go to right child
        solve(root->right, count, ans);

        // Backtracking:
        // Remove current digit before returning to parent
        count = count / 10;
    }

    int sumNumbers(TreeNode* root) {
        int count = 0;  // stores number formed along the path
        int ans = 0;    // final sum of all root-to-leaf numbers

        solve(root, count, ans);
        return ans;
    }
};

We go from root to leaf using DFS.

count stores the number formed so far.

Each step:

Multiply count by 10

Add current node value

When we reach a leaf, that number is complete → add it to ans.

Backtracking removes the last digit before exploring another path.