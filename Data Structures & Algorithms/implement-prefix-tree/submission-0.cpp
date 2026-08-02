class TrieNode {
    public:
        TrieNode* children[26];
        bool endOfWord;

        TrieNode() {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
            endOfWord = false;
        }
};

class PrefixTree {
    TrieNode* root;

public:

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cursor = root;
        for (char c : word) {
            int letter = c - 'a';
            if (!cursor->children[letter]) {
                cursor->children[letter] = new TrieNode();
            }
            cursor = cursor->children[letter];
        }
        cursor->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cursor = root;
        for (char c : word) {
            int letter = c - 'a';
            if (!cursor->children[letter]) return false;
            cursor = cursor->children[letter];
        }
        if (cursor->endOfWord) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cursor = root;
        for (char c : prefix) {
            int letter = c - 'a';
            if (!cursor->children[letter]) return false;
            cursor = cursor->children[letter];
        }
        return true;
    }
};
