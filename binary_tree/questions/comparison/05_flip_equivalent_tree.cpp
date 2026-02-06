class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        if (root1->val != root2->val) return false;

        // Try flip first
        if (flipEquiv(root1->left, root2->right) &&
            flipEquiv(root1->right, root2->left))
            return true;

        // Then try no-flip
        return flipEquiv(root1->left, root2->left) &&
               flipEquiv(root1->right, root2->right);
    }
};


If both nodes are NULL

Trees match at this point
→ return true

If only one node is NULL

Structure mismatch
→ return false

If node values are different

Cannot be flip-equivalent
→ return false

Check two possible configurations

Flip case

left of tree1 ↔ right of tree2

right of tree1 ↔ left of tree2

No-flip case

left ↔ left

right ↔ right

If either configuration fully matches

Trees are flip-equivalent
→ return true

If neither configuration matches

Trees are not flip-equivalent
→ return false