class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        
        vector<unordered_set<char>> precedes(26);

        unordered_set<char> letters;

        for (string word : words) {
            for (char c : word) letters.insert(c);
        }

        for (int i = 1; i < words.size(); ++i) {
            string word1 = words[i - 1];
            string word2 = words[i];
                
            int p1 = 0, p2 = 0;
            bool ordered = false;
            while (p1 < word1.length() && p2 < word2.length() && !ordered) {
                if (word1[p1] != word2[p2]) {
                    precedes[word1[p1] - 'a'].insert(word2[p2]);
                    ordered = true;
                }
                p1++;
                p2++;
            }
            if (!ordered && p1 < word1.length()) return "";
        }

        // for (int i = 0; i < 26; ++i) {
        //     cout << (char)(i + 'a') << ": ";
        //     for (char c : precedes[i]) cout << c << " ";
        //     cout << endl;
        // }
        // cout << endl;

        vector<int> inDegrees(26);
        for (int i = 0; i < 26; ++i) {
            for (char c : letters) {
                if (precedes[i].count(c)) {
                    inDegrees[c - 'a']++;
                }
            }
            
        }

        string ordering = "";

        queue<char> q;

        for (char c : letters) {
            if (inDegrees[c - 'a'] == 0) q.push(c);
        }

        // cout << "Letters: ";
        // for (char c : letters) {
        //     cout << c << " ";
        //     if (inDegrees[c - 'a'] == 0) q.push(c);
        // }
        // cout << endl;
        // cout << "inDegrees: " << endl;
        // for (char c : letters) {
        //     cout << c << ": " << inDegrees[c - 'a'] << endl;
        // }

        while (!q.empty()) {
            char c = q.front(); q.pop();

            if (letters.count(c)) ordering.push_back(c);
            letters.erase(c);
            for (char ch : precedes[c - 'a']) {
                inDegrees[ch - 'a']--;
                if (inDegrees[ch - 'a'] == 0) q.push(ch);
            }
        }

        if (letters.size() != 0) return "";

        return ordering;

    }
};
