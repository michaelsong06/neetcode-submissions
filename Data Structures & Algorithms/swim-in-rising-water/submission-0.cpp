class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> costs(n, vector<int>(m, INT_MAX));
        costs[0][0] = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int level = 0;

        bool reached = false;

        while (!pq.empty() && !reached) {
            auto [weight, coords] = pq.top(); pq.pop();
            int i = coords.first, j = coords.second;

            cout << grid[i][j] << " ";
            
            if (visited[i][j]) continue;
            visited[i][j] = true;

            level = max(level, grid[i][j]);

            if (i == n - 1 && j == m - 1) reached = true;

            for (auto [y, x] : dirs) {
                int di = i + y, dj = j + x;
                if (di < 0 || dj < 0 || di >= n || dj >= m) continue;
                pq.push({grid[di][dj], {di, dj}});
            }
        }

        return level;
    }
};
