class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxLen = 0;

        unordered_set<char> workingSet;

        for (int r = 0; r < s.length(); ++r) {
            while (workingSet.count(s[r])) {
                workingSet.erase(s[l]);
                l++;
            }
            workingSet.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};


// "abcabcbb"
//       ||
