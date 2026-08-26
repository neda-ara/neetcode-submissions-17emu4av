class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_buy = prices[0];

        for(int& price : prices) {
            max_profit = max(max_profit,price-min_buy);
            min_buy = min(price,min_buy);
        }

        return max_profit;
    }
};
