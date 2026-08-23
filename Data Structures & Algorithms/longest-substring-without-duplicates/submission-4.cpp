class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> window;

        int n = s.size();

        int res = 0;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            if (window.count(s[r])) {
                while (window.count(s[r])) {
                    window.erase(s[l]);
                    l++;
                }
            }
            window.insert(s[r]);
            res = max(res, r - l + 1);
        }

        return res;
    }
};
