class Solution {
public:
    void solve(int i, int j, string &curr, vector<vector<int>> &maze,
               vector<string> &ans, int n) {
        // Out of bounds or blocked
        if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0)
            return;

        // Destination reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(curr);
            return;
        }

        // Mark visited
        maze[i][j] = 0;

        // Move in fixed order: D, L, R, U (lexicographic)
        curr.push_back('D');
        solve(i + 1, j, curr, maze, ans, n);
        curr.pop_back();

        curr.push_back('L');
        solve(i, j - 1, curr, maze, ans, n);
        curr.pop_back();

        curr.push_back('R');
        solve(i, j + 1, curr, maze, ans, n);
        curr.pop_back();

        curr.push_back('U');
        solve(i - 1, j, curr, maze, ans, n);
        curr.pop_back();

        // Unmark visited
        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze) {
        vector<string> ans;
        int n = maze.size();
        if (n == 0 || maze[0][0] == 0) return ans;

        string curr;
        solve(0, 0, curr, maze, ans, n);
        return ans;
    }
};
