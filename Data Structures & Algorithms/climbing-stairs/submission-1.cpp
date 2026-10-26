class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return dfs(n,0,dp);
    }

    int dfs(int n, int i, vector<int>& dp) {
        if(i >= n) {
            return i == n;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        return dp[i] = dfs(n,i+1,dp) + dfs(n,i+2,dp);
    }
};
