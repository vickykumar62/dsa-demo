#include <algorithm> // for reverse

void postorder(TreeNode* root, vector<int>& ans) {

    // If tree is empty, nothing to traverse
    if (root == nullptr) return;

    // Stack to simulate recursion
    stack<TreeNode*> st;
    st.push(root);

    // Process all nodes
    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();

        // Add node value (root processed before children)
        ans.push_back(curr->val);

        // Push left first, then right
        // so right comes out first when reversing later
        if (curr->left) st.push(curr->left);
        if (curr->right) st.push(curr->right);
    }

    // Reverse to get Left → Right → Root
    reverse(ans.begin(), ans.end());
}

// Root → Right → Left → Reverse → Left → Right → Root