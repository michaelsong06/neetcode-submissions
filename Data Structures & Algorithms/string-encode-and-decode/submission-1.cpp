class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string s : strs) {
            encoded.append(s);
            encoded.push_back('|');
        }
        cout << encoded;
        return encoded;
    }

    vector<string> decode(string s) {
        
        vector<string> decoded;
        string current = "";
        for (char c : s) {
            if (c != '|') {
                current.push_back(c);
            } else {
                decoded.push_back(current);
                current = "";
            }
        }

        return decoded;
    }
};
