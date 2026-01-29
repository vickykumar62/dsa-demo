class Solution {
public:

    // This function builds the tree using inorder & postorder ranges
    TreeNode* solve(
        vector<int>& inorder,
        vector<int>& postorder,
        int in_start, int in_end,
        int post_start, int post_end,
        unordered_map<int,int>& mpp
    ) {

        // Base case:
        // If there are no elements to construct the tree
        if (in_start > in_end || post_start > post_end)
            return nullptr;

        // Last element of postorder is always the root
        TreeNode* root = new TreeNode(postorder[post_end]);

        // Find root position in inorder array
        int j = mpp[postorder[post_end]];

        // Number of nodes in left subtree
        int nums = j - in_start;

        // Recursively build left subtree
        root->left = solve(
            inorder, postorder,
            in_start, j - 1,                  // inorder range
            post_start, post_start + nums - 1, // postorder range
            mpp
        );

        // Recursively build right subtree
        root->right = solve(
            inorder, postorder,
            j + 1, in_end,                    // inorder range
            post_start + nums, post_end - 1,  // postorder range
            mpp
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();

        // Map to store value -> index of inorder traversal
        unordered_map<int,int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }

        // Build tree using full range of inorder & postorder
        return solve(inorder, postorder, 0, n - 1, 0, n - 1, mpp);
    }
};


// Key observations:

// Postorder = Left → Right → Root

// So last element of postorder is always the root

// Inorder = Left → Root → Right

// Root position in inorder tells:

// how many nodes go to the left subtree

// rest go to the right subtree

// Step-by-step logic:

// Take the last element of postorder → make it root

// Find this root in inorder

// Elements left of root in inorder → left subtree

// Elements right of root in inorder → right subtree

// Count left subtree size to split postorder correctly

// Recursively repeat for left and right parts

// Postorder gives root, Inorder splits left & right, recursion builds the tree