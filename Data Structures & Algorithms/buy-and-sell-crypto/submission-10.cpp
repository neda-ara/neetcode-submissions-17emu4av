class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), min_buy = prices[0], max_sell = 0;

        for(int i=0; i<n; i++) {
            max_sell = max(max_sell, prices[i]-min_buy);
            min_buy = min(min_buy, prices[i]);
        }

        return max_sell;
    }
};
