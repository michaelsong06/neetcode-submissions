class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= m; ++y) {
                dp[x][y] = (text1[x-1] == text2[y-1]) ? (1 + dp[x-1][y-1]) : max(dp[x-1][y], dp[x][y-1]);
            }
        }

        return dp[n][m];

    }
};
