class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0, n = prices.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                mp = max(mp, prices[j] - prices[i]);
            }
        }

        return mp;
    }
};
