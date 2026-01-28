void postorder(TreeNode* root, vector<int>& ans) {

    // If tree is empty, nothing to traverse
    if (root == nullptr) return;

    // Stack to simulate recursion
    stack<TreeNode*> st;

    // Keeps track of last processed node
    TreeNode* lastVisited = nullptr;

    // Continue until stack is empty and root is null
    while (!st.empty() || root) {

        // Step 1: Go as left as possible
        if (root) {
            st.push(root);
            root = root->left;
        }
        else {
            // Look at the top node without removing it
            TreeNode* peekNode = st.top();

            // Step 2: If right child exists and not yet visited, go right
            if (peekNode->right && lastVisited != peekNode->right) {
                root = peekNode->right;
            }
            else {
                // Step 3: Left and Right both done → process node
                ans.push_back(peekNode->val);
                lastVisited = peekNode;
                st.pop();
            }
        }
    }
}

// Step-by-step logic

// Go left
// Push nodes while moving left
// you have reached to null in left means left is done 

// Check the top of stack

// Decide

// If right child exists and not visited -> go right
// Else → process current node
// Mark visited
// lastVisited prevents revisiting right subtree

// One-line memory trick
// Process node only when right child is null or already visited
>>>>>>> a9fb6858054138535c9c38bec3901f9eaaafb3ea
