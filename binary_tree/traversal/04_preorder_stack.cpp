void preorder_using_stack(TreeNode* root, vector<int>& ans) {

    // If tree is empty, nothing to traverse
    if (root == nullptr) return;

    // Stack to simulate recursion
    stack<TreeNode*> st;

    // Start with root node
    st.push(root);

    // Run until all nodes are processed
    while (!st.empty()) {

        // Take the top node
        TreeNode* curr = st.top();
        st.pop();

        // Preorder: process node first
        ans.push_back(curr->val);

        // Push right child first
        // so that left child is processed first
        if (curr->right) st.push(curr->right);

        // Push left child
        if (curr->left) st.push(curr->left);
    }

    // Traversal completed
    return;
}
