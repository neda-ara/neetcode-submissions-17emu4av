class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), minH = grid[0][0], maxH = grid[0][0];
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                minH = min(minH, grid[r][c]);
                maxH = max(maxH, grid[r][c]);
            }
        }

        for (int t = minH; t < maxH; t++) {
            if (dfs(grid, visited, 0, 0, t)) {
                return t;
            }
            for (int r = 0; r < n; r++) {
                fill(visited[r].begin(), visited[r].end(), false);
            }
        }
        return maxH;
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int t) {
        int n = grid.size();

        if (r < 0 || c < 0 || r >= n || c >= n || visited[r][c] || t < grid[r][c]) {
            return false;
        }
        if (r == n - 1 && c == n - 1) {
            return true;
        }

        visited[r][c] = true;
        t = max(t, grid[r][c]);

        return dfs(grid, visited, r + 1, c, t) || dfs(grid, visited, r - 1, c, t) ||
               dfs(grid, visited, r, c + 1, t) || dfs(grid, visited, r, c - 1, t);
    }
};
