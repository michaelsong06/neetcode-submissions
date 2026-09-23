class Solution {
private:
    void dfs(vector<vector<char>>& grid, int& m, int& n, vector<vector<bool>>& visited, int i, int j) {
        if (grid[i][j] == '0') return;
        if (visited[i][j]) return;
        
        visited[i][j] = true;

        if (i > 0) dfs(grid, m, n, visited, i - 1, j);
        if (i < m - 1) dfs(grid, m, n, visited, i + 1, j);
        if (j > 0) dfs(grid, m, n, visited, i, j - 1);
        if (j < n - 1) dfs(grid, m, n, visited, i, j + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int numIslands = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) continue;
                if (grid[i][j] == '0') continue;
                dfs(grid, m, n, visited, i, j);
                numIslands++;
            }
        }

        return numIslands;
    }
};
