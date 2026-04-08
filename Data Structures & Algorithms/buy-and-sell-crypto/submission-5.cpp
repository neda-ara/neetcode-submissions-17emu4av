class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int maxProfit = 0;

        for(int& sell : prices) {
            maxProfit = max(maxProfit, sell - minBuy);
            minBuy = min(minBuy, sell);
        }
        return maxProfit;
    }
};
