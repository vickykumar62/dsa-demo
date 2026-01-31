class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;

        TreeNode* left  = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // both sides returned something → current root is LCA
        if (left && right) return root;

        // otherwise return non-null value
        return left ? left : right;

        return nullptr;
    }
};

LCA:
If root is p or q → return root
Ask left & right
If both return non-null → root is LCA
Else return non-null side

