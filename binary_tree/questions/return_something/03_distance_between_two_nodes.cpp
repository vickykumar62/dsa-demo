class Solution {
public:

    // Find Lowest Common Ancestor (LCA) of nodes a and b
    TreeNode* lcaFinder(TreeNode* root, int a, int b) {
        // Base case
        if (root == nullptr) return nullptr;

        // If current node matches a or b
        if (root->val == a || root->val == b) return root;

        // Search in left and right subtree
        TreeNode* left  = lcaFinder(root->left, a, b);
        TreeNode* right = lcaFinder(root->right, a, b);

        // If found in both sides, current node is LCA
        if (left && right) return root;

        // Otherwise return the found node
        return left ? left : right;
    }

    // Find distance from given root to target node
    void distanceFromNode(TreeNode* root, int target, int dist, int &ans) {
        // Stop if null or already found
        if (root == nullptr || ans != -1) return;  // Stop DFS once answer is found

        // Target found
        if (root->val == target) {
            ans = dist;
            return;
        }

        // DFS search
        distanceFromNode(root->left,  target, dist + 1, ans);
        distanceFromNode(root->right, target, dist + 1, ans);
    }

    // Return minimum distance between nodes a and b
    int findDistance(TreeNode* root, int a, int b) {

        // Step 1: Find LCA
        TreeNode* lca = lcaFinder(root, a, b);

        // Step 2: Distance from LCA to a
        int distA = -1;
        distanceFromNode(lca, a, 0, distA);

        // Step 3: Distance from LCA to b
        int distB = -1;
        distanceFromNode(lca, b, 0, distB);

        // Step 4: Total distance
        return distA + distB;
    }
};

Find LCA(a, b)

Find distance LCA → a

Find distance LCA → b

Add both