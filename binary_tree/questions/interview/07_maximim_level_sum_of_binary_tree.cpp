class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        if (root == nullptr) return 0;

        int maxSum = INT_MIN;   // stores maximum level sum
        int answerLevel = 1;    // level with maximum sum

        queue<TreeNode*> que;
        que.push(root);         // IMPORTANT: push root first

        int level = 0;

        // Standard BFS (level order traversal)
        while (!que.empty()) {

            int levelSize = que.size();  // number of nodes at current level
            int currentSum = 0;
            level++;  // move to next level

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = que.front();
                que.pop();

                currentSum += node->val;

                if (node->left)  que.push(node->left);
                if (node->right) que.push(node->right);
            }

            // Update maximum level sum
            if (currentSum > maxSum) {
                maxSum = currentSum;
                answerLevel = level;
            }
        }

        return answerLevel;
    }
};
