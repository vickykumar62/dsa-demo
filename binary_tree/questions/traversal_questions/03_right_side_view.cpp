class Solution {
public:

    // DFS function
    void solve(
        TreeNode* root,
        int h_level,                  // current level (height)
        unordered_set<int>& st,       // tracks visited levels
        vector<int>& ans
    ) {
        // Base case
        if (root == nullptr) return;

        // If this level is visited for the first time
        if (st.find(h_level) == st.end()) {
            st.insert(h_level);       // mark level as visited
            ans.push_back(root->val); // store rightmost value
        }

        // Visit right child first (IMPORTANT)
        solve(root->right, h_level + 1, st, ans);

        // Then visit left child
        solve(root->left, h_level + 1, st, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        unordered_set<int> st;

        // Start DFS from root at level 0
        solve(root, 0, st, ans);

        return ans;
    }
};

DFS goes right first

First node visited at each level = rightmost

unordered_set ensures:

Only one node per level is taken

No overwriting

class Solution {
public:
    void solve(TreeNode* root, int level, vector<int>& ans) {
        if (!root) return;

        // first node at this level
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        solve(root->right, level + 1, ans);
        solve(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};

First time we reach a level,
ans.size() == level