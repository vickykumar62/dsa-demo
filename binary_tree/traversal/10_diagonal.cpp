class Solution {
public:
    vector<int> diagonal(TreeNode* root) {

        vector<int> ans;
        if (root == nullptr) return ans;

        // Queue stores starting nodes of each diagonal
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            // Take one node from queue
            TreeNode* curr = q.front();
            q.pop();

            // Traverse current diagonal using right pointers
            while (curr != nullptr) {

                // Add current node
                ans.push_back(curr->val);

                // Left child goes to next diagonal
                if (curr->left)
                    q.push(curr->left);

                // Move right in same diagonal
                curr = curr->right;
            }
        }

        return ans;
    }
};

Right child → same diagonal
Left child  → next diagonal

Push root into queue

Pop one node → start one diagonal

Move right continuously (same diagonal)

Push every left child into queue (future diagonals)

Repeat until queue is empty