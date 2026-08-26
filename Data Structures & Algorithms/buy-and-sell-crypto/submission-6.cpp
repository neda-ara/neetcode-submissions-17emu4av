class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        for(int i=0; i<n-1; i++) {
            int buyFor = prices[i];
            for(int j=i+1; j<n; j++) {
                int sellAt = prices[j];
                profit = max(profit,sellAt-buyFor);
            }
        }
        return profit;
    }
};
