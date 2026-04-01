class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalDays = prices.size();
        vector<vector<int>> memo(totalDays, vector<int>(2,-1));
        return getMaxProfitFromDay(prices, 0, 0, memo);
    }

private:
    int getMaxProfitFromDay(vector<int>& prices, int currentDay, int isHoldingStock, vector<vector<int>>& memo) {
        if(currentDay == prices.size()) {
            return 0;
        }

        if(memo[currentDay][isHoldingStock] != -1) {
            return memo[currentDay][isHoldingStock];
        }

        int profitIfSkipped = getMaxProfitFromDay(prices, currentDay + 1, isHoldingStock, memo);
        int maxProfit = profitIfSkipped;

        if(isHoldingStock) {
            int profitIfSold = getMaxProfitFromDay(prices, currentDay + 1, 0, memo) + prices[currentDay];
            maxProfit = max(maxProfit, profitIfSold);
        } else {
            int profitIfBought = getMaxProfitFromDay(prices, currentDay + 1, 1, memo) - prices[currentDay];
            maxProfit = max(maxProfit, profitIfBought);
        }

        memo[currentDay][isHoldingStock] = maxProfit;
        return maxProfit;
    }
};