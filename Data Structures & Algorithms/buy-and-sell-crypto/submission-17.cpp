class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0], maxSell = 0;

        for(int i=0; i<prices.size(); i++) {
            int today = prices[i];
            maxSell = max(maxSell,today-minBuy);
            minBuy = min(minBuy,today);
        }

        return maxSell;
    }
};
