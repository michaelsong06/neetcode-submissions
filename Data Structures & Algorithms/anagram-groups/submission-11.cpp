class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> s;

        for (const string& str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            s[sorted].push_back(str);
        }

        vector<vector<string>> res;
        for (const auto& [sorted, str_set] : s) {
            res.push_back(str_set);
        }

        return res;
    }
};
