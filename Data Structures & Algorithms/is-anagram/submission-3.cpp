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

        map<char, int> freqsS, freqsT;
        for (char c : s) freqsS[c]++;
        for (char c : t) freqsT[c]++;
        
        return freqsS == freqsT;
    }
};
