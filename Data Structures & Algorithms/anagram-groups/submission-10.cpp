class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> m;

        for (string& str : strs) {
            vector<int> freqs(26, 0);
            for (char c : str) freqs[c - 'a']++;
            string key = "";
            for (int i = 0; i < 26; ++i) {
                key += to_string(freqs[i]);
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
