class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            int min_amt = INT_MAX;
            for (int c : coins) {
                if (i - c >= 0 && dp[i - c] != -1) {
                    min_amt = min(min_amt, 1 + dp[i - c]);
                }
            }
            dp[i] = (min_amt != INT_MAX) ? min_amt : -1;
        }

        return dp[amount];
    }
};
