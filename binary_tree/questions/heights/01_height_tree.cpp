class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Base case:
        // If tree is empty, depth is 0
        if (root == nullptr)
            return 0;

        // Find depth of left subtree
        int lh = maxDepth(root->left);

        // Find depth of right subtree
        int rh = maxDepth(root->right);

        // Current depth = 1 (current node) + max(left, right)
        return 1 + max(lh, rh);
    }
};

Depth of a tree = longest path from root to leaf

At each node:

Calculate left height

Calculate right height

Take the maximum

Add 1 for the current node
