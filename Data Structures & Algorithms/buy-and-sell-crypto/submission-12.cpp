class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0, n = prices.size(); 

        int l=0;
        for(int r=l+1; r<n; r++) {
            if(prices[r] < prices[l]) {
                l = r;
            }
            p = max(p, prices[r]-prices[l]);
        }
        return p;
    }
};
