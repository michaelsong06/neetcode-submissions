class TrieNode {
public:
    vector<TrieNode*> children;
    bool endOfWord;

    TrieNode() : children(26, nullptr), endOfWord(false) {}
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) {
        TrieNode* cursor = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cursor->children[i]) {
                cursor->children[i] = new TrieNode();
            }
            cursor = cursor->children[i];
        }
        cursor->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:

    bool dfs(string word, int j, TrieNode* node) {

        TrieNode* cursor = node;

        for (int i = j; i < word.size(); ++i) {

            char c = word[i];
            
            if (c == '.') {
                for (TrieNode* child : cursor->children) {
                    if (child && dfs(word, i + 1, child)) return true;
                }
                return false;
            } else {
                int letter = c - 'a';
                if (!cursor->children[letter]) return false;
                cursor = cursor->children[letter];
            }
        }
        return cursor->endOfWord;
    }
};
