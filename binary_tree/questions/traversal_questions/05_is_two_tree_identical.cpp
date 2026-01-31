class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Case 1: both nodes are null → same
        if (p == nullptr && q == nullptr)
            return true;

        // Case 2: one is null, other is not → not same
        if (p == nullptr || q == nullptr)
            return false;

        // Case 3: values are different → not same
        if (p->val != q->val)
            return false;

        // Case 4: check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

Recursively compare corresponding nodes

Stop immediately when:

structure differs

values differ

If all nodes match → trees are identical