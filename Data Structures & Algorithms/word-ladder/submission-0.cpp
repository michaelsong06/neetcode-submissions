class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<string> q;
        q.push(beginWord);

        set<string> visited;
        int transformations = 0;
        while (!q.empty()) {

            queue<string> temp = q;
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
            
            int levelsize = q.size();

            for (int k = 0; k < levelsize; ++k) {

                string current = q.front(); q.pop();

                if (visited.count(current)) continue;
                visited.insert(current);
                if (current == endWord) return transformations + 1;

                for (string word : wordList) {
                    int diff_count = 0;
                    for (int i = 0; i < word.length(); ++i) {
                        if (word[i] != current[i]) {
                            diff_count++;
                        }
                    }
                    if (diff_count == 1) q.push(word);
                }
            }
            transformations++;
        }

        return 0;
    }
};
