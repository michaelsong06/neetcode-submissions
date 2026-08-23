class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();

        unordered_map<char, int> freqs;
        int hf = 0;

        int res = 0;

        int l = 0;
        for (int r = 0; r < n; ++r) {
            freqs[s[r]]++;
            hf = max(hf, freqs[s[r]]);
            if (hf + k >= r - l + 1) {
                res = max(r - l + 1, res);
            } else {
                freqs[s[l]]--;
                l++;
            }
        }

        return res;
    }
};
