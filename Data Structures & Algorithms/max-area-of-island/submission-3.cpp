class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size(), n = grid[0].size();

        if (i < 0 || i > m - 1 || j < 0 || j > n - 1) return 0;
        if (grid[i][j] == 0) return 0;
        if (visited[i][j]) return 0;
        
        visited[i][j] = true;
        
        return 1 + dfs(grid, visited, i - 1, j) + dfs(grid, visited, i + 1, j) + dfs(grid, visited, i, j - 1) + dfs(grid, visited, i, j + 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int maxArea = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxArea = max(maxArea, dfs(grid, visited, i, j));
            }
        }

        return maxArea;
    }
};
