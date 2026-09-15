class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), max_profit = 0, min_buy = prices[0];

        for(int r=1; r<n; r++) {
            max_profit = max(max_profit, prices[r]-min_buy);
            min_buy = min(min_buy, prices[r]);
        }

        return max_profit;
    }
};
