class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh_count = 0, rotten_count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    rotten_count++;
                }
                else if (grid[i][j] == 1) fresh_count++;
            }
        }

        if (rotten_count == 0 && fresh_count != 0) return -1;
        if (rotten_count == 0 && fresh_count == 0) return 0; 

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int timer = 0;

        while (!q.empty()) {
            vector<pair<int, int>> rotten;
            while (!q.empty()) {
                rotten.emplace_back(q.front());
                q.pop();
            }
            for (auto [i, j] : rotten) {
                for (auto [y, x] : dirs) {
                    int di = i + y, dj = j + x;
                    if (di >= 0 && dj >= 0 && di < n && dj < m) {
                        if (grid[di][dj] == 1) {
                            q.push({di, dj});
                            grid[di][dj] = 2;
                        }
                    }
                }
            }
            timer++;
        }

        for (vector<int>& row : grid) {
            for (int fruit : row) {
                if (fruit == 1) return -1;
            }
        }

        return timer - 1;
    }
};
