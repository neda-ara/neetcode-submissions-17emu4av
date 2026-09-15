class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), max_profit = 0, l=0;

        for(int r=1; r<n; r++) {
            max_profit = max(max_profit,prices[r]-prices[l]);
            if(prices[r] < prices[l]) {
                l = r;
            }
        }

        return max_profit;
    }
};
