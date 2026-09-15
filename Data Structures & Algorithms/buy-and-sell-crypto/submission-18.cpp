class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), max_profit = 0;

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                max_profit = max(max_profit,prices[j]-prices[i]);
            }
        }

        return max_profit;
    }
};
