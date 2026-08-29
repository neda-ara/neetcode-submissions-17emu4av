class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit_max = 0;

        for(int i=0; i<n; i++) {
            int buy = prices[i];
            for(int j=i+1; j<n; j++) {
                int sell = prices[j];

                profit_max = max(profit_max,sell-buy);
            }
        }

        return profit_max;
    }
};
