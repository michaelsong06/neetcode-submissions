class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l = 0, r = 0;

        int maxLen = 0;

        unordered_map<char, int> freqs;
        char maxFreqChar;
        int maxFreq = 0;
        while (r < s.length()) {
            
            freqs[s[r]]++;
            if (freqs[s[r]] > maxFreq) {
                maxFreqChar = s[r];
                maxFreq = freqs[s[r]];
            }

            maxLen = max(maxLen, min(r - l + 1, maxFreq + k));
            
            if (r - l + 1 - maxFreq > k) {
                freqs[s[l]]--;
                l++;
            }

            r++;
        }

        return maxLen;
    }
};
