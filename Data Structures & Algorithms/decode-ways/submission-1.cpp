class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();

        vector<int> dp(n + 1);
        dp[0] = (s[0] != '0') ? 1 : 0;
        dp[1] = dp[0];

        for (int i = 2; i <= n; ++i) {
            int ways1 = (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] != '7' && s[i-1] != '8' && s[i-1] != '9')) ? dp[i-2] : 0;
            int ways2 = (s[i-1] != '0') ? dp[i-1] : 0; 
            dp[i] = ways1 + ways2;
        }

        return dp[n];
    }
};
