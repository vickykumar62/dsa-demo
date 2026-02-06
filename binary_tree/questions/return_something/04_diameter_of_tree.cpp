class Solution {
public:

    // Returns height of subtree
    // Updates diameter while returning height
    int solve(TreeNode* root, int &ans) {
        // Base case: empty tree has height 0
        if (root == nullptr) return 0;

        // Height of left subtree
        int left = solve(root->left, ans);

        // Height of right subtree
        int right = solve(root->right, ans);

        // Diameter passing through current node
        // = left height + right height
        ans = max(ans, left + right);

        // Return height of current subtree
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int ans = 0;          // stores maximum diameter
        solve(root, ans);     // compute height and update diameter
        return ans;
    }
};

Height = longest path from node → leaf

Diameter at a node =
height(left) + height(right)

While computing height:

Keep updating the maximum diameter

Final answer is stored in ans