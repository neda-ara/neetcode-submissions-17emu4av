class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit_max = 0, n = prices.size();

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int buy = prices[i], sell = prices[j];
                profit_max = max(profit_max, sell - buy);
            }
        }

        return profit_max;
    }
};
