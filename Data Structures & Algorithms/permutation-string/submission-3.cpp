class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> freqs(26, 0);
        for (char c : s1) freqs[c - 'a']++;

        int l = 0, r = s1.length() - 1;
        
        vector<int> window(26, 0);
        for (int i = 0; i < s1.length(); ++i) {
            window[s2[i] - 'a']++;
        }

        while (r < s2.length()) {
            for (int i = 0; i < 26; ++i) {
                if (window[i] > 0) {
                    cout << (char)(i + 'a') << ": " << window[i] << endl;
                }
            }
            cout << endl;
            if (window == freqs) return true;
            window[s2[++r] - 'a']++;
            window[s2[l++] - 'a']--;
        }

        return false;

    }
};
