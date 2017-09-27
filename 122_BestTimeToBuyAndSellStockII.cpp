
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int length = prices.size();
        for (int i = 0; i < length - 1; ++i){
            if (prices[i+1] > prices[i]){
                profit = profit + prices[i+1] - prices[i];
            }
        }
        return profit;
    }
};
