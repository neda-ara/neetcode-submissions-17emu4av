class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit_max = 0, n = prices.size(), min_buy = prices[0];

        for(int i=1; i<n; i++) {
            profit_max = max(profit_max, prices[i] - min_buy);
            min_buy = min(min_buy,prices[i]);
        }

        return profit_max;
    }
};
