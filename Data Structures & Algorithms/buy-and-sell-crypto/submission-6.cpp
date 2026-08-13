class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        
        int maxProfit = 0;

        int l = 0;
        for (int r = 1; r < n; ++r) {
            maxProfit = max(maxProfit, prices[r] - prices[l]);
            while (l < r && prices[r] < prices[l]) {
                l++;
            }
        }

        return maxProfit;
    }
};
