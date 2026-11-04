class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        return min(
            dfs(cost, 0, memo), dfs(cost, 1, memo)
        );
    }


    int dfs(vector<int>& cost, int i, vector<int>& memo) {
        if(i >= cost.size()) {
            return 0;
        }
        if(memo[i] != -1) {
            return memo[i];
        }
        memo[i] = cost[i] + min(
            dfs(cost, i+1, memo),
            dfs(cost, i+2, memo)
        );
        return memo[i];
    }
};
