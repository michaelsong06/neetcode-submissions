class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> freqs;

        int n = s.size();

        int res = 0;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            freqs[s[r]]++;
            if (freqs[s[r]] > 1) {
                while (freqs[s[r]] > 1) {
                    freqs[s[l]]--;
                    l++;
                }
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
