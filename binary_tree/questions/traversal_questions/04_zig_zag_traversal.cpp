class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        // If tree is empty, return empty answer
        if (root == nullptr) return ans;

        // Queue for level order traversal (BFS)
        queue<TreeNode*> que;
        que.push(root);

        // decider = true  → left to right
        // decider = false → right to left
        bool decider = true;

        // Process tree level by level
        while (!que.empty()) {

            // Number of nodes at current level
            int size = que.size();

            // If direction is left to right
            if (decider == true) {

                vector<int> level;

                for (int i = 0; i < size; i++) {
                    TreeNode* curr = que.front();
                    que.pop();

                    // Normal order insertion
                    level.push_back(curr->val);

                    // Push children for next level
                    if (curr->left) que.push(curr->left);
                    if (curr->right) que.push(curr->right);
                }

                ans.push_back(level);
            }
            // If direction is right to left
            else {

                // Pre-allocate vector to fill from back
                vector<int> level(size, 0);

                for (int i = size - 1; i >= 0; i--) {
                    TreeNode* curr = que.front();
                    que.pop();

                    // Insert values from right to left
                    level[i] = curr->val;

                    // Push children for next level
                    if (curr->left) que.push(curr->left);
                    if (curr->right) que.push(curr->right);
                }

                ans.push_back(level);
            }

            // Change direction for next level
            decider = !decider;
        }

        return ans;
    }
};

// Zigzag Level Order:
// BFS traversal
// Use flag to change direction
// Left→Right: push_back
// Right→Left: fill vector from back