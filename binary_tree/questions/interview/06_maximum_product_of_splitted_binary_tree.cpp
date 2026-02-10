class Solution {
public:
    long long maxProductAns = 0;

    // Step 1: Calculate total sum of the entire tree
    long long getTotalSum(TreeNode* root) {
        if (root == nullptr) return 0;

        return root->val +
               getTotalSum(root->left) +
               getTotalSum(root->right);
    }

    // Step 2: DFS that returns subtree sum
    long long dfs(TreeNode* root, long long totalSum) {
        if (root == nullptr) return 0;

        // Get subtree sums from left and right
        long long leftSum  = dfs(root->left, totalSum);
        long long rightSum = dfs(root->right, totalSum);

        // Current subtree sum
        long long currentSubtreeSum = root->val + leftSum + rightSum;

        // If we cut the edge above this node:
        // one part = currentSubtreeSum
        // other part = totalSum - currentSubtreeSum
        long long product =
            currentSubtreeSum * (totalSum - currentSubtreeSum);

        // Update maximum product
        maxProductAns = max(maxProductAns, product);

        // Return subtree sum to parent
        return currentSubtreeSum;
    }

    int maxProduct(TreeNode* root) {
        // Compute total tree sum once
        long long totalSum = getTotalSum(root);

        // DFS to compute subtree sums and products
        dfs(root, totalSum);

        // Return answer modulo 1e9+7
        return maxProductAns % 1000000007;
    }
};
