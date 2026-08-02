class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        wordSet.erase(beginWord);

        int transformations = 0;
        while (!q.empty()) {
            
            int levelsize = q.size();

            for (int k = 0; k < levelsize; ++k) {

                string current = q.front(); q.pop();

                if (current == endWord) return transformations + 1;

                for (int i = 0; i < current.length(); ++i) {
                    for (int c = 'a'; c <= 'z'; ++c) {
                        string candidate = current;
                        candidate[i] = c;
                        if (wordSet.count(candidate)) {
                            q.push(candidate);
                            wordSet.erase(current);
                        }
                    }
                }
            }
            transformations++;
        }

        return 0;
    }
};
