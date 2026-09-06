class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= s.size(); ++i) {
            dp[i] = false;
            for (int j = 1; j <= i; ++j) {
                dp[i] = dp[i] || (dp[i-j] && wordSet.count(s.substr(i-j, j)));
            }
        }

        return dp[s.size()];

        /*
        dp[i] = oneOf[j](dp[i-j] && is_in_set(s[i-j..i-1]))
        */
    }
};
