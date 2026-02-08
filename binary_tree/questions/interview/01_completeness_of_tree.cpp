class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;

        queue<TreeNode*> q;
        q.push(root);

        bool nullFound = false;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                // Once NULL is found, all future nodes must be NULL
                nullFound = true;
            } else {
                // If we already saw NULL and now see a node → not complete
                if (nullFound) return false;

                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};

Rule to remember

BFS guarantees left → right order

Key idea

NULL means a gap

Condition

Node after a gap ⇒ NOT complete

Think of filling seats :

Seats fill left to right

Once you see an empty seat (NULL)

You must not see any person (node) later

whenever you write the complete binary tree in array , you will not find the gap and if you it 
means it is not a complete binary tree 

class Solution {
public:
    void solve(TreeNode* root,
               long long index,          // index of current node (heap-style)
               long long &maxIndex,       // maximum index seen so far
               long long &count) {        // total number of nodes

        // Base case: no node here
        if (root == nullptr) return;

        // Count every real (non-null) node
        count++;

        // Track the largest index assigned
        maxIndex = max(maxIndex, index);

        /*
            Assign indices like a complete binary tree:
            left child  -> 2 * index
            right child -> 2 * index + 1
        */
        solve(root->left, 2 * index, maxIndex, count);
        solve(root->right, 2 * index + 1, maxIndex, count);
    }

    bool isCompleteTree(TreeNode* root) {
        // Empty tree is complete
        if (root == nullptr) return true;

        long long maxIndex = 0;  // largest index used
        long long count = 0;     // total nodes in tree

        // Start DFS with root index = 1
        solve(root, 1, maxIndex, count);

        /*
            In a complete binary tree:
            indices are continuous from 1 to count

            If there is any gap:
            maxIndex becomes greater than count
        */
        return maxIndex == count;
    }
};


Key idea

Treat the tree like an array representation of a complete binary tree.

Root index = 1

Left child = 2 * index

Right child = 2 * index + 1

Property of a complete tree

If a tree is complete, then
max index assigned == number of nodes

If there’s a gap, indices jump → maxIndex > count