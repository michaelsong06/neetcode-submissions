class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

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

                for (int i = 0; i < current.length(); ++i) {
                    for (int c = 'a'; c <= 'z'; ++c) {
                        string candidate = current;
                        candidate[i] = c;
                        if (wordSet.count(candidate)) q.push(candidate);
                    }
                }
            }
            transformations++;
        }

        return 0;
    }
};
