class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> m;

        for (string& str : strs) {
            vector<int> freqs(26, 0);
            for (char c : str) freqs[c - 'a']++;
            m[freqs].push_back(str);
        }

        vector<vector<string>> output;
        for (auto [key, anagrams] : m) {
            output.push_back(anagrams);
        }

        return output;

    }
};
