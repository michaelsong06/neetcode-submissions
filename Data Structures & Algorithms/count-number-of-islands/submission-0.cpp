class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int islands = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j]) continue;
                if (grid[i][j] == '0') continue;
                dfs(grid, visited, i, j);
                islands++;
            }
        }

        return islands;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {

        if (grid[i][j] == '0') return;
        if (visited[i][j]) return;

        visited[i][j] = true;

        if (i - 1 >= 0) {
            dfs(grid, visited, i - 1, j);
        }
        if (j - 1 >= 0) {
            dfs(grid, visited, i, j - 1);
        }
        if (i + 1 < grid.size()) {
            dfs(grid, visited, i + 1, j);
        }
        if (j + 1 < grid[0].size()) {
            dfs(grid, visited, i, j + 1);
        }
    }
};
