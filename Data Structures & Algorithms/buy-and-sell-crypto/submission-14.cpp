class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                ans = max(ans,prices[j]-prices[i]);
            }
        }
        return max(0,ans);
    }
};
