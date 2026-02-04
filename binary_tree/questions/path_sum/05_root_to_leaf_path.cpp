class Solution {
public:
    // DFS to collect root → leaf paths
    void solve(TreeNode* root, vector<int>& curr, vector<vector<int>>& ans) {
        // Base case: no node
        if (root == nullptr) return;

        // Add current node value to path
        curr.push_back(root->val);

        // If leaf node, store the current path
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(curr);
        }

        // Go to left child
        solve(root->left, curr, ans);

        // Go to right child
        solve(root->right, curr, ans);

        // Backtrack: remove current node before returning
        curr.pop_back();
    }

    vector<vector<int>> Paths(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        vector<int> curr;  // stores current path
        solve(root, curr, ans);

        return ans;
    }
};

Start from the root

Keep adding nodes to a temporary path (curr)

When a leaf node is reached:

Store the path in ans

Go left, then right

While returning, remove the last node (backtracking)