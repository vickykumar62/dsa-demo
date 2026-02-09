class Solution {
public:
    void solve(TreeNode* root, int val, int depth, int level) {
        // Base case
        if (root == nullptr) return;

        /*
            When we reach level = depth - 1,
            we add new nodes as children of current node
        */
        if (level == depth - 1) {
            TreeNode* oldLeft = root->left;
            TreeNode* oldRight = root->right;

            // Create new left node
            TreeNode* newLeft = new TreeNode(val);
            newLeft->left = oldLeft;
            root->left = newLeft;

            // Create new right node
            TreeNode* newRight = new TreeNode(val);
            newRight->right = oldRight;
            root->right = newRight;

            return; // stop going deeper from this node
        }

        // Continue DFS
        solve(root->left, val, depth, level + 1);
        solve(root->right, val, depth, level + 1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Special case: new root
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        solve(root, val, depth, 1);
        return root;
    }
};

I traverse the tree, and when I reach depth − 1, I insert new nodes as children of every node at that level.

Step 1: Handle special case (depth = 1)

If D == 1

Create a new node with value val

Make the current root its left child

Return the new node as root

👉 Because adding at depth 1 means new root

Step 2: Traverse the tree (DFS)

Start DFS from root

Keep track of current level

Step 3: Stop exactly at level D - 1

When currentLevel == D - 1

This node is the parent of the new row

Do NOT go deeper

Step 4: Insert new nodes

For each node at level D - 1:

Save original children

oldLeft = root->left

oldRight = root->right

Create new nodes with value val

New left node

New right node

Reattach old children

newLeft->left = oldLeft

newRight->right = oldRight

Attach new nodes to current root

root->left = newLeft

root->right = newRight