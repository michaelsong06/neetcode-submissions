class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        
        int maxProfit = 0;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            maxProfit = max(maxProfit, prices[r] - prices[l]);
            if (prices[r] < prices[l]) {
                l = r;
            }
        }

        return maxProfit;
    }
};
