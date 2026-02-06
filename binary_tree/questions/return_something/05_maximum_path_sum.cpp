class Solution {
public:

    // This function returns:
    // 👉 maximum path sum starting from current node
    // 👉 and going UPWARD to its parent (only one side allowed)
    int solve(TreeNode* root, int &maxPathSum) {
        if (root == nullptr) return 0;

        // Get maximum path sum from left subtree
        int leftSubtreeSum = solve(root->left, maxPathSum);

        // Get maximum path sum from right subtree
        int rightSubtreeSum = solve(root->right, maxPathSum);

        // Case 1:
        // Path passes through current node and uses BOTH left & right
        // (this path cannot be extended to parent)
        int pathThroughCurrent =
            root->val + leftSubtreeSum + rightSubtreeSum;

        // Case 2:
        // Path uses current node and ONLY left side
        int pathUsingLeft =
            root->val + leftSubtreeSum;

        // Case 3:
        // Path uses current node and ONLY right side
        int pathUsingRight =
            root->val + rightSubtreeSum;

        // Best path that includes current node and can be extended upward
        int bestSingleSidePath =
            max(pathUsingLeft, pathUsingRight);

        // Update global answer considering ALL possibilities:
        // 1) left + root + right
        // 2) root + left
        // 3) root + right
        // 4) root alone
        maxPathSum = max( { maxPathSum,pathThroughCurrent, 
                        bestSingleSidePath,root->val } );

        // Return value to parent:
        // parent can choose only ONE side or the node itself
        return max(root->val, bestSingleSidePath);
    }

    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;

        int maxPathSum = INT_MIN;
        solve(root, maxPathSum);
        return maxPathSum;
    }
};


What we do at every node (Postorder)

We first ask left, then ask right, then decide at current node.

Get answer from children

Left subtree returns its maximum path sum

Right subtree returns its maximum path sum

These are partial paths coming upward.

Try all possible paths at current node
At current node, these are the only valid possibilities:

Left + Root + Right
→ path passes through current node
→ cannot be extended to parent

Root + Left
→ path goes upward using left side

Root + Right
→ path goes upward using right side

Root alone
→ useful when children give bad (negative) paths

Update global answer
Compare global answer with all above possibilities
Store the maximum path found so far

Decide what to return to parent
Parent can take only one side


