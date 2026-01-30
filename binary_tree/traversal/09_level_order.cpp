class Solution {
public:

    // DFS to store nodes based on vertical & horizontal levels
    void solve(
        TreeNode* root,
        int v_l,   // vertical level (column)
        int h_l,   // horizontal level (row)
        map<int, map<int, multiset<int>>>& mpp
    ) {
        // Base case
        if (root == nullptr) return;

        // Store node value at its (vertical, horizontal) position
        mpp[v_l][h_l].insert(root->val);

        // Go left: vertical decreases, horizontal increases
        if (root->left)
            solve(root->left, v_l - 1, h_l + 1, mpp);

        // Go right: vertical increases, horizontal increases
        if (root->right)
            solve(root->right, v_l + 1, h_l + 1, mpp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // Data structure:
        // vertical -> horizontal -> sorted values
        map<int, map<int, multiset<int>>> mpp;

        // Start DFS from root at (0,0)
        solve(root, 0, 0, mpp);

        vector<vector<int>> ans;

        // Traverse vertical columns from left to right
        for (auto p : mpp) {
            vector<int> col;

            // Traverse rows from top to bottom
            for (auto q : p.second) {

                // Insert sorted values (handles same position case)
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};

Outer map (v_l)
 ensures columns are processed left to right

Inner map (h_l)
 ensures nodes are processed top to bottom

multiset<int>
 handles same position nodes
 automatically keeps values sorted

map< vertical ,
     map< horizontal ,
          multiset<values> >
   >

for (auto p : mpp)
p.first → vertical level (column)

p.second → all rows in that column

map ensures left → right order

for (auto q : p.second)
q.first → horizontal level (row)

q.second → nodes at same position

map ensures top → bottom order

Multiple nodes can have:

same vertical

same horizontal

Problem asks to return them in sorted order

multiset:

keeps duplicates

auto-sorts values