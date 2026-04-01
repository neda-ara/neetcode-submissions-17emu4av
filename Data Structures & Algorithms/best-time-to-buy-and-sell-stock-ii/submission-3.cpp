class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currBuy = 0, nextBuy = 0, currSell = 0, nextSell = 0;

        for(int day = prices.size()-1; day>=0; --day) {
            int currDayStockPrice = prices[day];

            currBuy = max(nextBuy, nextSell - currDayStockPrice);
            currSell = max(nextSell, nextBuy + currDayStockPrice);
            nextBuy = currBuy;
            nextSell = currSell;
        }

        return currBuy;
    }
};