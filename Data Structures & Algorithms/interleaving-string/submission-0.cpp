class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();
        int x = s3.size();
        if (n + m != x) return false;
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int l = 1; l <= n; ++l) {
            dp[l][0] = (s3[l-1] == s1[l-1]) && dp[l-1][0];
        }
        for (int l = 1; l <= m; ++l) {
            dp[0][l] = (s3[l-1] == s2[l-1]) && dp[0][l-1];
        }

        for (int l1 = 1; l1 <= n; ++l1) {
            for (int l2 = 1; l2 <= n; ++l2) {
                dp[l1][l2] = (dp[l1-1][l2] && (s3[l1+l2-1] == s1[l1-1])) 
                             || (dp[l1][l2-1] && (s3[l1+l2-1] == s2[l2-1]));
            }
        }

        return dp[n][m];
    }
};
