class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return (root->left == nullptr && root->right == nullptr);
    }

    void solve(TreeNode* root, string &ans) {
        if (root == nullptr) return;

        // If this is a leaf, append value + separator
        if (isLeaf(root)) {
            ans += to_string(root->val);
            ans += "#";   // separator to avoid ambiguity
        }

        // DFS: left to right order is preserved
        solve(root->left, ans);
        solve(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string leaves1 = "";
        string leaves2 = "";

        solve(root1, leaves1);
        solve(root2, leaves2);

        return leaves1 == leaves2;
    }
};


// instead of keeping the leaf in vector append it in string with separator 