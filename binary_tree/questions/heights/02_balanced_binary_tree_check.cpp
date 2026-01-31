class Solution {
public:

    // Returns height if subtree is balanced
    // Returns -1 if subtree is NOT balanced
    int height(TreeNode* root) {

        // Base case
        if (root == nullptr)
            return 0;

        // Get left subtree height
        int lh = height(root->left);
        if (lh == -1) return -1;   // left subtree unbalanced

        // Get right subtree height
        int rh = height(root->right);
        if (rh == -1) return -1;   // right subtree unbalanced

        // If height difference > 1, tree is unbalanced
        if (abs(lh - rh) > 1)
            return -1;

        // Otherwise return height
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

Balanced Tree:
Return -1 if unbalanced
Check BOTH left and right subtree results
One wrong variable breaks logic