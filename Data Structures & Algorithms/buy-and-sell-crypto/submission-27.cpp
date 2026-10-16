class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0, n = prices.size(), mb;

        for(int i=0; i<n; i++) {
            mp = max(mp, prices[i]-mb);
            mb = min(mb, prices[i]);
        }

        return mp;
    }
};
