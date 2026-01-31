class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    // Add left boundary (excluding leaf nodes)
    void addLeft(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root->left;
        while (curr) {
            if (!isLeaf(curr))
                ans.push_back(curr->val);

            // prefer left, else go right
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    // Add all leaf nodes (DFS)
    void addLeaves(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;

        if (isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    // Add right boundary (excluding leaf nodes)
    void addRight(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr))
                temp.push_back(curr->val);

            // prefer right, else go left
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        // reverse to get bottom-up order
        reverse(temp.begin(), temp.end());
        ans.insert(ans.end(), temp.begin(), temp.end());
    }

    vector<int> boundaryTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        // root is always part of boundary (if not leaf)
        if (!isLeaf(root))
            ans.push_back(root->val);

        addLeft(root, ans);
        addLeaves(root, ans);
        addRight(root, ans);

        return ans;
    }
};

Root
Left (no leaf)
Leaves
Right (reverse, no leaf)
