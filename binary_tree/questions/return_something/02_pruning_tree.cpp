class Solution {
public:

    // Prunes the tree and returns the new root
    TreeNode* pruneTree(TreeNode* root) {

        // Base case: empty node
        if(root == nullptr) return nullptr;

        // Step 1: prune left and right subtrees first
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // Step 2: decide for current node
        // If current node value is 0
        // AND both left and right subtrees are removed
        // then this node does not contain any '1'
        if(root->val == 0 && root->left == nullptr && root->right == nullptr) {
            return nullptr;  // prune this node
        }

        // Otherwise, keep this node
        return root;
    }
};

Go to left and right first (postorder)

After pruning children:

If both children are null AND current value is 0
→ remove this node (return nullptr)

Otherwise
→ keep this node

Children already tell us whether they contain a 1 or not.
If both are gone AND I am 0 → I am useless → delete me.