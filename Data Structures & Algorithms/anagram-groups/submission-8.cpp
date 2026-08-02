class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> m;

        for (string& str : strs) {
            map<char, int> freqs;
            for (char c : str) freqs[c]++;
            string key;
            for (int c = 'a'; c <= 'z'; ++c) {
                if (freqs.count(c)) {
                    key += (to_string(freqs[c]));
                } else key.push_back('0');
                key.push_back('|');
            }
            m[key].push_back(str);
        }

        vector<vector<string>> output;
        for (auto [key, anagrams] : m) {
            output.push_back(anagrams);
        }

        return output;

    }
};
