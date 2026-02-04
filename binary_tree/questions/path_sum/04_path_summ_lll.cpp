class Solution {
public:
    // This function checks all downward paths starting
    // from the given root and counts paths with sum = targetSum
    void helper(TreeNode* root, int &ans, int targetSum, long long &count) {
        if (root == nullptr) return;

        // Add current node value to the running sum
        count += root->val;

        // If current path sum equals target, count it
        if (count == targetSum) {
            ans++;
        }

        // Continue the same path downward
        helper(root->left, ans, targetSum, count);
        helper(root->right, ans, targetSum, count);

        // Backtracking: remove current node value
        count -= root->val;
    }

    // This function chooses every node as a starting point
    void solve(TreeNode* root, int &ans, int targetSum) {
        if (root == nullptr) return;

        long long count = 0;

        // Count all paths starting from this node
        helper(root, ans, targetSum, count);

        // Try starting paths from left and right child
        solve(root->left, ans, targetSum);
        solve(root->right, ans, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;

        // Try all possible starting nodes
        solve(root, ans, targetSum);

        return ans;
    }
};

Pick a starting node
solve() treats every node as a possible start of a path.

Go downward from that node

helper():
keeps adding node values (count)
checks if count == targetSum
continues only downwards
backtracks properly

This guarantees:
path can start anywhere
path goes only parent → child
path can end anywhere

class Solution {
public:
    // DFS function using prefix sum technique
    void solve(TreeNode* root, int &ans,
               int targetSum, long long &curr_sum,
               unordered_map<long long, int> &prefix) {

        // If node is NULL, stop
        if (root == nullptr) return;

        // Add current node value to running sum
        curr_sum += root->val;

        // Check if there exists a previous prefix sum
        // such that removing it gives targetSum
        auto it = prefix.find(curr_sum - targetSum);
        if (it != prefix.end()) {
            // Add number of valid paths ending here
            ans += it->second;
        }

        // Store current prefix sum
        prefix[curr_sum]++;

        // Continue DFS downward
        solve(root->left, ans, targetSum, curr_sum, prefix);
        solve(root->right, ans, targetSum, curr_sum, prefix);

        // Backtracking:
        // remove current prefix sum and value
        prefix[curr_sum]--;
        curr_sum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;

        // Map to store prefix sums and their frequency
        unordered_map<long long, int> prefix;

        long long curr_sum = 0;

        // Base case: sum 0 occurs once
        // helps in counting paths starting anywhere
        prefix[0] = 1;

        // Start DFS
        solve(root, ans, targetSum, curr_sum, prefix);

        return ans;
    }
};

Keep sum from root → current node (currSum)

If currSum − target appeared before, that path in between = target

Store currSum, go down, remove on backtrack
