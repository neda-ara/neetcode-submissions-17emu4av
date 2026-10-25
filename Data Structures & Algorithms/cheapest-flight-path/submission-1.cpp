class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX);
        prices[src] = 0;

        for(int i=0; i<=k; i++) {
            vector<int> tmpPrices = prices;
            for(auto& flight : flights) {
                int s = flight[0], d = flight[1], p = flight[2];
                if(prices[s] == INT_MAX) {
                    continue;
                }
                int priceToD = prices[s] + p;
                if(priceToD < tmpPrices[d]) {
                    tmpPrices[d] = priceToD;
                }
            }
            prices = tmpPrices;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
