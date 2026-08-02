class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // if (s.length() != t.length()) return false;

        // multiset<char> tset(t.begin(), t.end());

        // for (char c : s) {
        //     auto it = tset.find(c);
        //     if (it != tset.end()) {
        //         tset.erase(it);
        //     } else return false;
        // }

        // return true;

        if (s.length() != t.length()) return false;

        map<char, int> freqs;
        for (char c : s) freqs[c]++;

        for (char c : t) {
            freqs[c]--;
            if (freqs[c] < 0) return false;
        }
        return true;
    }
};
