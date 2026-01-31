class Solution {
public:
    vector<int> topView(TreeNode *root) {

        // vertical level -> node value
        map<int, int> mpp;

        // queue stores: node and its vertical level
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});

        while (!que.empty()) {

            Node* curr = que.front().first;
            int level = que.front().second;
            que.pop();

            // store first node seen at this vertical level
            if (mpp.find(level) == mpp.end()) {
                mpp[level] = curr->val;
            }

            if (curr->left)
                que.push({curr->left, level - 1});

            if (curr->right)
                que.push({curr->right, level + 1});
        }

        vector<int> ans;
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

Why BFS is perfect here

BFS goes level by level

Top nodes are visited first

Once stored, never overwrite

if(mpp.find(level) == mpp.end())
This ensures only the first node at each vertical is taken.
