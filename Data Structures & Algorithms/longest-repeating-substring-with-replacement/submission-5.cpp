class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int longest = 0;

        int l = 0;
        int r = 0;

        unordered_map<char, int> freqs;
        char maxChar = 'x';

        while (r < s.size()) {
            
            freqs[s[r]]++;
            if (freqs[s[r]] > freqs[maxChar]) {
                maxChar = s[r];
            }

            int longestInWindow = min(r - l + 1, freqs[maxChar] + k);
            if (longestInWindow > longest) {
                longest = longestInWindow;
            } else {
                freqs[s[l]]--;
                l++;
            }

            r++;
        }

        return longest;
    }
};
