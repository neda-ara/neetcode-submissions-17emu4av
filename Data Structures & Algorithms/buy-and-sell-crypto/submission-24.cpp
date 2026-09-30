class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, n = prices.size(), min_buy = prices[0];

        for(int i=1; i<n; i++) {
            max_profit = max(max_profit,prices[i]-min_buy);
            min_buy = min(min_buy,prices[i]);
        }

        return max_profit;
    }
};
