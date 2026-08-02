class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh_count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) fresh_count++;
            }
        }

        if (q.empty()) {
            if (fresh_count != 0) return -1;
            else return 0; 
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int timer = 0;

        while (!q.empty()) {
            int num_rotten = q.size();
            for (int x = 0; x < num_rotten; ++x) {
                auto [i, j] = q.front(); q.pop();
                for (auto [y, x] : dirs) {
                    int di = i + y, dj = j + x;
                    if (di >= 0 && dj >= 0 && di < n && dj < m) {
                        if (grid[di][dj] == 1) {
                            q.push({di, dj});
                            grid[di][dj] = 2;
                            fresh_count--;
                        }
                    }
                }    
            }
            timer++;
        }

        if (fresh_count > 0) return -1;

        return timer - 1;
    }
};
