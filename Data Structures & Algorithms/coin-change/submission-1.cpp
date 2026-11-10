class Solution {
   public:
    unordered_map<int, int> memo;

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(coins, amount);
        return minCoins == INT_MAX ? -1 : minCoins;
    }

    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (memo.count(amount)) {
            return memo[amount];
        }

        int res = INT_MAX;
        for (int& coin : coins) {
            if (amount - coin >= 0) {
                int result = dfs(coins, amount - coin);
                if (result != INT_MAX) {
                    res = min(res, 1 + result);
                }
            }
        }

        memo[amount] = res;
        return memo[amount];
    }
};
