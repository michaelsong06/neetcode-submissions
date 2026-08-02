class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        
        int maxProf = 0;

        for (int sell = 0; sell < prices.size(); ++sell) {
            if (prices[buy] < prices[sell]) {
                maxProf = max(maxProf, prices[sell] - prices[buy]);
            } else {
                buy = sell;
            }
        }

        return maxProf;

    }
};
