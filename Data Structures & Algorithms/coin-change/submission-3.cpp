class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int amt = 1; amt <= amount; amt++) {
            for (int& coin : coins) {
                if (coin <= amt) {
                    dp[amt] = min(dp[amt], dp[amt - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
