class Solution {
public:

    // This function:
    // 1) returns the SUM of the subtree rooted at 'root'
    // 2) updates 'countEle' with total number of nodes in this subtree
    // 3) updates 'ans' if current node satisfies the condition
    int solve(TreeNode* root, int &ans, int &countEle) {
        
        // Base case: empty tree
        // Sum = 0, count = 0
        if (root == nullptr) return 0;

        // These will store node counts from left & right subtree
        int leftCount = 0;
        int rightCount = 0;

        // Get sum from left subtree
        // leftCount will be updated inside recursive call
        int leftSum = solve(root->left, ans, leftCount);

        // Get sum from right subtree
        // rightCount will be updated inside recursive call
        int rightSum = solve(root->right, ans, rightCount);

        // Total nodes in current subtree
        int totalCount = leftCount + rightCount + 1;

        // Total sum of current subtree
        int totalSum = leftSum + rightSum + root->val;

        // Check condition:
        // If average of subtree == current node value
        if (totalSum / totalCount == root->val)
            ans++;

        // Update node count for parent call
        countEle = totalCount;

        // Return subtree sum to parent
        return totalSum;
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;        // Stores final answer
        int countEle = 0;  // Dummy variable for root call

        solve(root, ans, countEle);
        return ans;
    }
};

Ask left → get sum + count

Ask right → get sum + count

Add current node

Check average condition

Return sum, update count