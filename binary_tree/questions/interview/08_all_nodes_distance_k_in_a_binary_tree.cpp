class Solution {
public:

    // Step 1: Build parent mapping so we can move upward in tree
    void traverse(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent) {
        if (root == nullptr) return;

        if (root->left) {
            parent[root->left] = root;   // store parent
            traverse(root->left, parent);
        }

        if (root->right) {
            parent[root->right] = root;  // store parent
            traverse(root->right, parent);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if (root == nullptr) return {};

        vector<int> ans;

        // If k == 0 → only target itself
        if (k == 0) {
            ans.push_back(target->val);
            return ans;
        }

        // Parent map (to treat tree like an undirected graph)
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root] = nullptr;
        traverse(root, parent);

        // BFS from target
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> que;

        que.push(target);
        visited[target] = true;

        int distance = 0;

        // Perform BFS level by level
        while (!que.empty() && distance < k) {

            int size = que.size();
            distance++;

            for (int i = 0; i < size; i++) {

                TreeNode* curr = que.front();
                que.pop();

                // Move to left child
                if (curr->left && !visited[curr->left]) {
                    que.push(curr->left);
                    visited[curr->left] = true;
                }

                // Move to right child
                if (curr->right && !visited[curr->right]) {
                    que.push(curr->right);
                    visited[curr->right] = true;
                }

                // Move to parent
                if (parent[curr] && !visited[parent[curr]]) {
                    que.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }

        // Remaining nodes in queue are exactly distance K away
        while (!que.empty()) {
            ans.push_back(que.front()->val);
            que.pop();
        }

        return ans;
    }
};

Tree normally allows only downward movement.
But here we need:

left

right

parent

So treat tree as undirected graph.

Build Parent Map

So every node can move upward.

BFS from Target

Start from target

Expand level by level

Stop after k levels

Return Remaining Queue

Nodes in queue = distance K
