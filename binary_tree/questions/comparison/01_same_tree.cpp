class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both nodes are null
        if (p == nullptr && q == nullptr) return true;

        // Case 2: one is null, other is not
        if (p == nullptr || q == nullptr) return false;

        // Case 3: values are different
        if (p->val != q->val) return false;

        // Compare left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

We walk both trees together

At every node:

structure must match

value must match

DFS guarantees we check every position

If any mismatch → false immediately.