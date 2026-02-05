class Solution {
public:
    // Compare two trees to check if they are mirror images
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both nodes are NULL → mirror at this position
        if (p == nullptr && q == nullptr) return true;

        // Case 2: one is NULL and the other is not → not mirror
        if (p == nullptr || q == nullptr) return false;

        // Case 3: values are different → not mirror
        if (p->val != q->val) return false;

        // Mirror comparison:
        // left of p must match right of q
        // right of p must match left of q
        return isSameTree(p->left, q->right) &&
               isSameTree(p->right, q->left);
    }

    // Check if a tree is symmetric around its center
    bool isSymmetric(TreeNode* root) {
        // Empty tree or single node tree is always symmetric
        if (root == nullptr ||
            (root->left == nullptr && root->right == nullptr))
            return true;

        // Compare left and right subtrees as mirror
        return isSameTree(root->left, root->right);
    }
};

How do we check mirror?

At every step:

both nodes must exist or both must be null

values must be equal

cross compare children

left ↔ right

right ↔ left

