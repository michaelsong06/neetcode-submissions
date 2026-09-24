class Solution {
private:
    int dfsImpl(vector<vector<char>>& grid) {
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
    void dfs(vector<vector<char>>& grid, int& m, int& n, vector<vector<bool>>& visited, int i, int j) {
        if (grid[i][j] == '0') return;
        if (visited[i][j]) return;
        
        visited[i][j] = true;

        if (i > 0) dfs(grid, m, n, visited, i - 1, j);
        if (i < m - 1) dfs(grid, m, n, visited, i + 1, j);
        if (j > 0) dfs(grid, m, n, visited, i, j - 1);
        if (j < n - 1) dfs(grid, m, n, visited, i, j + 1);
    }

    int bfsImpl(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int numIslands = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (grid[i][j] == '0') continue;
                if (visited[i][j]) continue;

                q.emplace(i, j);

                while (!q.empty()) {
                    auto cell = q.front(); q.pop();
                    int y = cell.first, x = cell.second;

                    if (grid[y][x] == '0') continue;
                    if (visited[y][x]) continue;

                    visited[y][x] = true;

                    if (y > 0 && !visited[y-1][x]) q.emplace(y-1, x);
                    if (y < m - 1 && !visited[y+1][x]) q.emplace(y+1, x);
                    if (x > 0 && !visited[y][x-1]) q.emplace(y, x-1);
                    if (x < n - 1 && !visited[y][x+1]) q.emplace(y, x+1);
                }

                numIslands++;
            }
        }

        return numIslands;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        return bfsImpl(grid);
    }
};
