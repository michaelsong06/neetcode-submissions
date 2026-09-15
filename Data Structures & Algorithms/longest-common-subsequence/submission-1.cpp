class Solution {
private:
    int longestSubseq(const string& text1, const string& text2, int x, int y) {

        if (x == 0 || y == 0) return 0;

        if (text1[x-1] == text2[y-1]) return 1 + longestSubseq(text1, text2, x-1, y-1);
        else return max(longestSubseq(text1, text2, x-1, y), longestSubseq(text1, text2, x, y-1));

    }
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
