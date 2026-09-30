class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, n = prices.size();

        for(int i=0; i<n-1; i++) {
            int buy_for = prices[i];
            for(int j=i+1; j<n; j++) {
                int sell_at = prices[j];

                if(sell_at > buy_for) {
                    max_profit = max(max_profit,sell_at-buy_for);
                }
            }
        }

        return max_profit;
    }
};
