class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0, n = prices.size(), l = 0;

        for(int r=0; r<n; r++) {
            mp = max(mp, prices[r] - prices[l]);
            if(prices[r] < prices[l]) {
                l = r;
            }
        }

        return mp;
    }
};
