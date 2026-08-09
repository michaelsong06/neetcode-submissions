class Solution {
public:
    bool isPalindrome(string s) {
        
        int l = 0, r = s.size() - 1;

        while (l <= r && !isalnum(s[l])) l++;
        while (l <= r && !isalnum(s[r])) r--;

        while (l <= r) {
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
            while (!isalnum(s[l])) l++;
            while (!isalnum(s[r])) r--;
        }

        return true;
    }
};
