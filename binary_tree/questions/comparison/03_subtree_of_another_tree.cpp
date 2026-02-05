class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    void traverse(TreeNode* root, TreeNode* subRoot, bool &ans) {
        if (root == nullptr || ans) return;

        // Try matching subtree only when values match
        if (root->val == subRoot->val) {
            if (isSameTree(root, subRoot)) {
                ans = true;
                return;   // stop only when subtree is found
            }
        }

        // Keep searching
        traverse(root->left, subRoot, ans);
        traverse(root->right, subRoot, ans);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;

        bool ans = false;
        traverse(root, subRoot, ans);
        return ans;
    }
};

Main idea

Traverse every node of the main tree

Treat each node as a possible root of the subtree

Verify full match only when values match

Step-by-step logic

If subRoot is NULL

It is always a subtree
→ return true

If root is NULL

But subRoot is not NULL
→ subtree cannot exist
→ return false

Traverse the main tree (DFS)

At each node:

If node value ≠ subRoot value
→ move to left and right

If node value == subRoot value
→ check full subtree using isSameTree

Full subtree check

Compare structure + values

If match found → stop traversal and return true

If not matched → continue traversal

After traversal

If no match found anywhere
→ return false