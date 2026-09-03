class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxSell = 0, n = prices.size(); 

        int minBuy = prices[0];
        for(int i=1; i<n; i++) {
            maxSell = max(maxSell, prices[i] - minBuy);
            minBuy = min(minBuy, prices[i]);
        }
        return maxSell;
    }
};
