class Solution {
public:
    // Map: height -> list of nodes at that height
    // Ordered map ensures heights are processed in increasing order
    map<int, vector<int>> mp;

    int collectNodeWithHeight(TreeNode* root) {
        // Base case: empty subtree has height 0
        if (!root)
            return 0;

        /*
            Postorder traversal:
            first compute heights of left and right subtrees
        */
        int leftHeight  = collectNodeWithHeight(root->left);
        int rightHeight = collectNodeWithHeight(root->right);

        /*
            Height of current node:
            leaf node => height = 1
            parent => 1 + max(left, right)
        */
        int height = 1 + max(leftHeight, rightHeight);

        // Group nodes by their height
        mp[height].push_back(root->val);

        // Return height to parent
        return height;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        // Fill the map with nodes grouped by height
        collectNodeWithHeight(root);

        vector<vector<int>> result;

        /*
            Collect nodes in increasing height order:
            height 1  -> first removed leaves
            height 2  -> second round
            ...
        */
        for (auto &it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};


it’s about turning a tree into layers using DFS.

Convert the tree into heights from bottom to top

Leaves have height 1

Their parents get height 2

Root gets the maximum height

Each height = one round of leaf removal

assign a height to each node