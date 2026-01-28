void inorder(TreeNode* root, vector<int>& ans) {

    // If tree is empty, no traversal needed
    if (root == nullptr) return;

    // Stack to simulate recursion
    stack<TreeNode*> st;

    // Continue until all nodes are processed
    while (root != nullptr || !st.empty()) {

        // Go as left as possible
        while (root) {
            st.push(root);
            root = root->left;
        }

        // Process the leftmost node
        TreeNode* curr = st.top();
        st.pop();

        // Inorder: process node after left subtree
        ans.push_back(curr->val);

        // Move to right subtree
        root = curr->right;
    }
}
