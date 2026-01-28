void single_iteration(TreeNode* root,
                      vector<int>& pre,
                      vector<int>& in,
                      vector<int>& post) {

    // If tree is empty
    if (root == nullptr) return;

    // Stack stores node and its state
    // state 1 → preorder
    // state 2 → inorder
    // state 3 → postorder
    stack<pair<TreeNode*, int>> st;

    // Start with root in state 1
    st.push({root, 1});

    while (!st.empty()) {

        auto curr = st.top();
        st.pop();

        // State 1: Preorder (Root)
        if (curr.second == 1) {
            pre.push_back(curr.first->val);

            // Move to next state
            st.push({curr.first, 2});

            // Go to left subtree
            if (curr.first->left)
                st.push({curr.first->left, 1});
        }

        // State 2: Inorder (Left done, now Root)
        else if (curr.second == 2) {
            in.push_back(curr.first->val);

            // Move to next state
            st.push({curr.first, 3});

            // Go to right subtree
            if (curr.first->right)
                st.push({curr.first->right, 1});
        }

        // State 3: Postorder (Left + Right done)
        else {
            post.push_back(curr.first->val);
        }
    }
}
