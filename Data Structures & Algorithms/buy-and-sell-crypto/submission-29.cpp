class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit_max = 0, n = prices.size();
        int l = 0;

        for(int r=1; r<n; r++) {
            profit_max = max(profit_max, prices[r] - prices[l]);
            if(prices[r] < prices[l]) {
                l = r;
            }
        }

        return profit_max;
    }
};
