class Solution {
public:
    int solve(TreeNode* root, int &ans) {
        // Empty subtree: ignore it in comparisons
        if (root == nullptr)
            return INT_MIN;

        // Leaf node is always a single-valued subtree
        if (root->left == nullptr && root->right == nullptr) {
            ans++;
            return root->val;
        }

        // Get values from left and right subtrees
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        // Check if left or right subtree breaks single-valued property
        bool leftBad  = (left != INT_MIN && left != root->val);
        bool rightBad = (right != INT_MIN && right != root->val);

        if (leftBad || rightBad) {
            return INT_MAX;   // mark as NOT single-valued
        }

        // Current subtree is single-valued
        ans++;
        return root->val;
    }

    int singlevalued(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};


A subtree is single-valued if both children are either empty or have the same value as the root.

“Return-a-signal DFS”

You return normal data when things are OK
You return a special value when things are NOT OK

Use INT_MIN / INT_MAX as signals, not real values.

Normal return → “everything is fine”
return root->val;

Special return → “ignore / stop / invalid”
return INT_MIN;  // nothing here (null case)
return INT_MAX;  // broken subtree

When to use this technique

Use INT_MIN / INT_MAX signalling when:

DFS must return data + status

You want to avoid:

global flags

extra structs

pair / tuple returns