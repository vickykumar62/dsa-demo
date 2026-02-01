class Solution {
public:
    // check if current node is a leaf node
    bool isLeaf(TreeNode* root) {
        return (root->left == nullptr && root->right == nullptr);
    }

    // DFS + backtracking
    void solve(TreeNode* root, int &count, int &targetSum, bool &ans) {
        if (root == nullptr) return;

        // add current node value to path sum
        count += root->val;

        // check only at leaf node
        if (isLeaf(root) && count == targetSum)
            ans = true;

        // go left
        solve(root->left, count, targetSum, ans);

        // go right
        solve(root->right, count, targetSum, ans);

        // backtrack: remove current node value
        count -= root->val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        int count = 0;

        solve(root, count, targetSum, ans);
        return ans;
    }
};


Every time you step on a node → add its value to a bag (count)

When you reach a leaf:

check if the bag value equals targetSum

When you go back (return from recursion):

remove that node’s value from the bag
(because you are leaving that path)