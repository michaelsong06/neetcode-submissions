class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> charcodes;
        for (char c : "abcdefghijklmnopqrstuvwxyz") {
            charcodes[c] = c - 'a' + 1;
        }
        int s1product = 1;
        for (char c : s1) {
            s1product *= charcodes[c];
        }

        int l = 0;
        int r = s1.length() - 1;

        while (r < s2.length()) {
            bool valid = true;
            int thisproduct = 1;
            for (int i = l; i <= r; ++i) {
                thisproduct *= charcodes[s2[i]];
            }
            if (s1product == thisproduct) return true;
            l++;
            r++;
        }

        return false;
    }
};
