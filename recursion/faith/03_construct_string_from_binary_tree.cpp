class Solution {
public:
    string tree2str(TreeNode* root) {

        // Base Case:
        // If the node is null, return an empty string.
        // This stops recursion when we reach beyond leaf nodes.
        if(root == nullptr) return "";

        // Recursive Step:
        // Recursively convert the left and right subtree into strings.
        // We trust that these recursive calls correctly build
        // the string representation of the smaller subtrees.
        string left = tree2str(root->left);
        string right = tree2str(root->right);

        // Case 1: If both children are null (leaf node)
        // Simply return the node value.
        if(root->left == nullptr && root->right == nullptr)
            return to_string(root->val);

        // Case 2: Left child is null but right child exists
        // We must include empty parentheses for the left child
        // to preserve the correct tree structure.
        if(root->left == nullptr)
            return to_string(root->val) + "(" + ")" + "(" + right + ")";

        // Case 3: Right child is null but left child exists
        // Only include the left subtree parentheses.
        if(root->right == nullptr)
            return to_string(root->val) + "(" + left + ")";

        // Case 4: Both children exist
        // Include both left and right subtree representations.
        return to_string(root->val) + "(" + left + ")" + "(" + right + ")";
    }
};

// Each node trusts recursion to build left and right subtree strings, then simply wraps them as
// value(left)(right) while preserving structure rules.