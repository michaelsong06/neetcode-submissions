class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size(), m = t.size();

        if (n < m) return "";
        
        unordered_map<char, int> t_map;
        for (char c : t) t_map[c]++;

        unordered_map<char, int> window;

        int min_len = numeric_limits<int>::max();
        vector<int> res = {-1, -1};

        int have = 0, need = t_map.size();

        for (int l = 0, r = 0; r < n; ++r) {
            window[s[r]]++;
            if (t_map.count(s[r]) && t_map[s[r]] == window[s[r]]) have++;
            while (have == need) {
                if (r - l + 1 < min_len) {
                    res = {l, r - l + 1};
                    min_len = r - l + 1;
                }
                window[s[l]]--;
                if (t_map.count(s[l]) && t_map[s[l]] > window[s[l]]) have--;
                l++;
            }
        }

        return (min_len == numeric_limits<int>::max()) ? "" : s.substr(res[0], res[1]);
    }
};
