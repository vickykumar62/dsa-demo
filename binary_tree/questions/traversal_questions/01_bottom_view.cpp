class Solution {
public:
    vector<int> bottomView(TreeNode* root) {

        // vertical level -> node value
        map<int, int> mpp;

        // queue stores: node and its vertical level
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int level = it.second;

            // overwrite is safe in BFS
            mpp[level] = node->val;

            if (node->left)
                q.push({node->left, level - 1});

            if (node->right)
                q.push({node->right, level + 1});
        }

        vector<int> ans;
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

Problem with DFS

DFS traversal order ≠ depth order

DFS goes deep on one side first

A deep node can be visited early

A shallow node can be visited later

Later visit overwrites, even if it is NOT deeper

Overwrite works only in BFS
Queue ensures deeper nodes come later