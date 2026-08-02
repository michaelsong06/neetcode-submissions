class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // int minBuy = INT_MAX;
        // int maxProfit = 0;

        // for (int i = 0; i < prices.size(); ++i) {
        //     minBuy = min(minBuy, prices[i]);
        //     maxProfit = max(maxProfit, prices[i] - minBuy);
        // }

        // return maxProfit;

        int l = 0, r = 0;

        int maxProfit = 0;

        while (r < prices.size()) {

            maxProfit = max(maxProfit, prices[r] - prices[l]);

            while (l < r && prices[l] > prices[r]) l++;

            r++;
        }

        return maxProfit;

    }
};
