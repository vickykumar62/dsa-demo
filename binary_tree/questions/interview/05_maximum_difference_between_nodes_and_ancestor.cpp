class Solution {
public:
    // Computes the maximum difference between a fixed ancestorValue
    // and all nodes in its subtree
    void findMaxDiffWithAncestor(TreeNode* node,
                                 int ancestorValue,
                                 int &maxDiffWithThisAncestor) {
        // Base case: no node
        if (node == nullptr) return;

        // Update max difference using current node
        maxDiffWithThisAncestor =
            max(maxDiffWithThisAncestor,
                abs(ancestorValue - node->val));

        // Continue checking left and right subtrees
        findMaxDiffWithAncestor(node->left,
                                ancestorValue,
                                maxDiffWithThisAncestor);
        findMaxDiffWithAncestor(node->right,
                                ancestorValue,
                                maxDiffWithThisAncestor);
    }

    // Traverses each node and treats it as an ancestor
    void traverseTree(TreeNode* node, int &globalMaxDiff) {
        // Base case
        if (node == nullptr) return;

        // Stores max difference for current node as ancestor
        int currentAncestorMaxDiff = INT_MIN;

        // Compare this node (as ancestor) with all its descendants
        findMaxDiffWithAncestor(node,
                                node->val,
                                currentAncestorMaxDiff);

        // Update global answer
        globalMaxDiff = max(globalMaxDiff,
                            currentAncestorMaxDiff);

        // Move to next possible ancestors
        traverseTree(node->left, globalMaxDiff);
        traverseTree(node->right, globalMaxDiff);
    }

    int maxAncestorDiff(TreeNode* root) {
        int globalMaxDiff = INT_MIN;

        // Start traversal
        traverseTree(root, globalMaxDiff);

        return globalMaxDiff;
    }
};

“Fix one ancestor → scan all descendants”

class Solution {
public:
    // DFS function
    // maxSeen → maximum value seen so far on path from root to current node
    // minSeen → minimum value seen so far on path from root to current node
    // ans     → stores the maximum ancestor difference found so far
    void solve(TreeNode* root, int &maxSeen, int &minSeen, int &ans) {
        // Base case: reached beyond leaf
        if (root == nullptr) return;

        // Save current path state (for backtracking)
        int prevMax = maxSeen;
        int prevMin = minSeen;

        // Update answer using current node vs ancestor min/max
        ans = max({
            ans,
            abs(root->val - minSeen),
            abs(root->val - maxSeen)
        });

        // Update path min and max including current node
        maxSeen = max(maxSeen, root->val);
        minSeen = min(minSeen, root->val);

        // Recurse to children with updated path values
        solve(root->left, maxSeen, minSeen, ans);
        solve(root->right, maxSeen, minSeen, ans);

        // Restore previous path values (backtracking)
        maxSeen = prevMax;
        minSeen = prevMin;
    }

    int maxAncestorDiff(TreeNode* root) {
        // Initialize min and max using root value
        int maxSeen = root->val;
        int minSeen = root->val;

        int ans = 0;

        // Start DFS from root
        solve(root, maxSeen, minSeen, ans);

        return ans;
    }
};


For any node, the best ancestor is either the minimum or maximum on its path.

Start from root

Carry:

minSeen → smallest ancestor so far

maxSeen → largest ancestor so far

At each node:

Update answer using
|node − minSeen| and |node − maxSeen|

Update min/max and go deeper

Backtrack path values