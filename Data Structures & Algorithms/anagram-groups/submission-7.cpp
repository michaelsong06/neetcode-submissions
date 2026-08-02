class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> m;

        for (string& str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(str);
        }

        vector<vector<string>> output;
        for (auto [key, anagrams] : m) {
            output.push_back(anagrams);
        }

        return output;

    }
};
