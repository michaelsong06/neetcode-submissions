class Solution {
public:
    bool exists = false;

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (backtrack(board, visited, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int index, int i, int j) {

        if (index == word.length()) return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;

        if (visited[i][j]) return false;

        if (word[index] != board[i][j]) return false;

        cout << board[i][j] << " ";

        visited[i][j] = true;
        
        bool res = backtrack(board, visited, word, index + 1, i - 1, j) ||
                    backtrack(board, visited, word, index + 1, i, j - 1) ||
                    backtrack(board, visited, word, index + 1, i + 1, j) ||
                    backtrack(board, visited, word, index + 1, i, j + 1);

        visited[i][j] = false;
        return res;
    }
};
