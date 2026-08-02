class Solution {
public:
    bool isAnagram(string s, string t) {
        
        string s_s = s;
        string t_s = t;
        sort(s_s.begin(), s_s.end());
        sort(t_s.begin(), t_s.end());
        return s_s == t_s;
    }
};
