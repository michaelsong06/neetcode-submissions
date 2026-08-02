class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        
        for (const auto& str: strs) {
            vector<int> count(26, 0);
            for (char c: str) {
                count[c - 'a']++;
            }
            string key = "";
            for (int freq: count) {
                key += "|" + to_string(freq);
            }
            cout << key << "\n";
            res[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& kvp: res) {
            result.push_back(kvp.second);
        }
        return result;
    }
};
