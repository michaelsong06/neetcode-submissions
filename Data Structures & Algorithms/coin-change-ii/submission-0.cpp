class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int c : coins) {
            for (int x = 1; x <= amount; ++x) {
                if (x - c >= 0) dp[x] += dp[x-c];
            }
        }

        for (int x : dp) cout << x << " ";
        cout << endl;
        
        return dp[amount];
    }
};
