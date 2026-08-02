class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, 0);

        for (int i = 1; i <= amount; ++i) {
            dp[i] = 10001;
            for (int c : coins) {
                if (i - c >= 0) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        for (int x : dp) cout << x << " ";
        cout << endl;

        return (dp[amount] > 10000) ? -1 : dp[amount];
    }
};
