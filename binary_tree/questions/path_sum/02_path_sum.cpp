class Solution {
public:

    // Check if the current node is a leaf node
    bool isLeaf(TreeNode* root){
        return (root->left == nullptr && root->right == nullptr);
    }

    void solve(TreeNode* root,
               int &count,                  // current path sum
               int &targetSum,              // required sum
               vector<int>& temp,           // current path nodes
               vector<vector<int>>& ans) {  // all valid paths

        // Base case: reached null node
        if(root == nullptr) return;

        // Step 1: include current node
        count += root->val;
        temp.push_back(root->val);

        // Step 2: if it is a leaf and sum matches, store the path
        if(isLeaf(root) && count == targetSum){
            ans.push_back(temp);  // store a COPY of current path
        }

        // Step 3: explore left and right children
        solve(root->left, count, targetSum, temp, ans);
        solve(root->right, count, targetSum, temp, ans);

        // Step 4: backtrack (remove current node before returning)
        count -= root->val;
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;

        // If tree is empty, no paths exist
        if(root == nullptr) return ans;

        vector<int> temp;  // to store current path
        int count = 0;     // current sum

        solve(root, count, targetSum, temp, ans);
        return ans;
    }
};

While going down:

add node value to count

write node value in notebook (temp)

When you reach a leaf:

if count == targetSum

copy notebook into answer

While coming back:

erase last written value

subtract node value from count

This ensures:

each path is handled independently

no mixing of values from different paths