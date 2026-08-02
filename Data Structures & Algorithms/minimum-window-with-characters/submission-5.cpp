class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> tFreqs, windowFreqs;
        for (char c : t) tFreqs[c]++;
        
        int l = 0;
        int r = 0;

        int have = 0;
        int need = tFreqs.size();

        vector<int> res = {-1, -1};
        int resLen = 1001;

        while (r < s.length()) {
            windowFreqs[s[r]]++;

            if (tFreqs.count(s[r]) && windowFreqs[s[r]] == tFreqs[s[r]]) {
                have++;
            }

            while (have == need) {
                if (have == need && resLen > r - l + 1) {
                    resLen = r - l + 1;
                    res = {l, r};
                    cout << "new shortest found: " << r - l + 1 << "\n";
                }
                

                windowFreqs[s[l]]--;
                if (tFreqs.count(s[l]) && windowFreqs[s[l]] < tFreqs[s[l]]) {
                    have--;
                }
                l++;

                cout << s.substr(l, r - l + 1) << "\n";
            }
            
            r++;
            cout << s.substr(l, r - l + 1) << "\n";
        }

        return (resLen == 1001) ? "" : s.substr(res[0], res[1] - res[0] + 1);

    }
};
