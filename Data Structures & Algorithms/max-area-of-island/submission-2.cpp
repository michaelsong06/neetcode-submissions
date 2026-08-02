class Solution {
private:

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& grid, int i, int j) {

        if (grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        
        int area = 1;
        for (auto [y, x] : dirs) {
            int di = i + y, dj = j + x;
            if (di < 0 || dj < 0 || di >= grid.size() || dj >= grid[0].size()) continue;
            area += dfs(grid, di, dj);
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) continue;
                max_area = max(max_area, dfs(grid, i, j));
            }
        }

        return max_area;
    }
};
