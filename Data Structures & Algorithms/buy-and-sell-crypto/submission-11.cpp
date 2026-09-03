class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0, n = prices.size();

        for(int i=0; i<n; i++) {
            int buy = prices[i];
            for(int j=i+1; j<n; j++) {
                int sell = prices[j];

                p = max(p, sell - buy);
            }
        }
        return p;
    }
};
