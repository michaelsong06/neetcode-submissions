class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // check rows
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> s;
            for (char c : board[i]) {
                if (s.count(c)) return false;
                if (c == '.') continue;
                if (c <= '0' || c > '9') return false;
                s.insert(c);
            }
        }

        // check cols
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> s;
            for (int j = 0; j < 9; ++j) {
                char c = board[j][i];
                if (s.count(c)) return false;
                if (c == '.') continue;
                if (c <= '0' || c > '9') return false;
                s.insert(c);
            }
        }

        // check each box
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<char> s;
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        char c = board[i + x][j + y];
                        if (s.count(c)) return false;
                        if (c == '.') continue;
                        if (c <= '0' || c > '9') return false;
                        s.insert(c);
                    }
                }
            }
        }

        return true;

    }
};
