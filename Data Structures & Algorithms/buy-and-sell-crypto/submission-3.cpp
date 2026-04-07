class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;

        if(n==0 || n==1) {
            return 0;
        }

        vector<int> maxSuffix(n-1);
        maxSuffix[n-2] = prices[n-1];

        for(int i=n-3; i>=0; i--) {
            maxSuffix[i] = max(prices[i+1],maxSuffix[i+1]);
        }

        for(int i=0; i<n-1; i++) {
            maxProfit = max(maxProfit, maxSuffix[i]-prices[i]);
        }

        return maxProfit;
    }
};
