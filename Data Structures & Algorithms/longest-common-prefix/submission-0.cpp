class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int min_len = INT_MAX;
        for (string& str : strs) {
            min_len = min(min_len, int(str.length()));
        }

        string prefix = "";
        for (int i = 0; i < min_len; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[0][i]) return prefix;
            }
            prefix.push_back(strs[0][i]);
        }

        return prefix;
    }
};