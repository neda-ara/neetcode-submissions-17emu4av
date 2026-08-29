class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1, profit = 0;

        while(r < prices.size()) {
            int buy = prices[l], sell = prices[r];

            if(sell < buy) {
                l = r;
            } else {
                profit = max(profit,sell-buy);
            }
            r++;
        }
        return profit;
    }
};
