class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case: empty tree
        if (root == nullptr) return nullptr;

        // Step 1: swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Step 2: invert left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        // Return the root of inverted tree
        return root;
    }
};

If the node is NULL → nothing to invert

Swap left and right child of current node

Recursively invert left subtree

Recursively invert right subtree

Do this for every node