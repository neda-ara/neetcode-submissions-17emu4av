class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n + 1, -1));
        return dfs(0, 0, m, n, memo);
    }

    int dfs(int i, int j, int m, int n, vector<vector<int>>& memo) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (i >= m || j >= n) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        return memo[i][j] = dfs(i + 1, j, m, n, memo) + dfs(i, j + 1, m, n, memo);
    }
};
