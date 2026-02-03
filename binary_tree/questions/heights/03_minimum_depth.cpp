class Solution {
public:
    // A node is a leaf if it has no left and no right child
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    // DFS function to explore all root-to-leaf paths
    void solve(TreeNode* root, int &count, int &ans) {
        // If node is NULL, stop
        if (root == nullptr) return;

        // Include current node in path
        count++;

        // If current path is already longer than the best answer,
        // no need to go deeper (pruning)
        if (count >= ans) {
            count--;        // backtrack before returning
            return;
        }

        // If leaf node found, update minimum depth
        if (isLeaf(root)) {
            ans = min(ans, count);
        }

        // Go to left subtree
        solve(root->left, count, ans);

        // Go to right subtree
        solve(root->right, count, ans);

        // Remove current node from path (backtracking)
        count--;
    }

    int minDepth(TreeNode* root) {
        // Empty tree has depth 0
        if (root == nullptr) return 0;

        int count = 0;          // current path length
        int ans = INT_MAX;      // minimum depth found so far

        // Start DFS from root
        solve(root, count, ans);

        return ans;
    }
};

We do DFS (root → leaf).

count keeps track of current depth.

When we reach a leaf, we update the minimum depth.

INT_MAX helps us compare easily without special cases.

Backtracking ensures count is correct for every path.

class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> que;
        que.push(root);

        int ans = 0;

        while (!que.empty()) {
            int size = que.size();
            ans++;   // depth increases level by level

            for (int i = 0; i < size; i++) {
                TreeNode* curr = que.front();
                que.pop();

                // first leaf found → minimum depth
                if (isLeaf(curr)) return ans;

                if (curr->left)  que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
        }
        return ans;
    }
};

BFS goes level by level

First leaf encountered is the shortest path

No need to explore deeper levels