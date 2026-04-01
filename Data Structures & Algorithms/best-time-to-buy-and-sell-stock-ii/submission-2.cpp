class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n+1, vector<int>(2,0));

        for(int i=n-1; i>=0; --i) {
            memo[i][0] = max(memo[i+1][0], -prices[i] + memo[i+1][1]);
            memo[i][1] = max(memo[i+1][1], prices[i] + memo[i+1][0]);
        }

        return memo[0][0];
    }
};