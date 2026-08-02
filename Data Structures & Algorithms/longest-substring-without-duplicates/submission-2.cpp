class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> window;

        int max_len = 0;

        int l = 0;
        int r = 0;
        while (r < s.length()) {
            if (window.count(s[r])) {
                while (window.count(s[r])) {
                    window.erase(s[l++]);
                }
            }
            window.insert(s[r]);
            max_len = max(max_len, r - l + 1);
            r++;
        }

        return max_len;
    }
};


// "abcabcbb"
//       ||
