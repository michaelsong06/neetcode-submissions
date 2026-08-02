class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> delays(n + 1, INT_MAX);
        delays[k] = 0;
        delays[0] = 0;

        for (int i = 0; i < n - 1; ++i) {
            vector<int> temp_delays = delays;

            for (vector<int>& edge : times) {
                int u = edge[0];
                int v = edge[1];
                int t = edge[2];

                if (delays[u] == INT_MAX) continue;
                
                if (delays[u] + t < temp_delays[v]) {
                    temp_delays[v] = delays[u] + t;
                }
            }
            delays = temp_delays;
            temp_delays = delays;
        }

        for (int i = 0; i < n + 1; ++i) {
            cout << i << ": " << delays[i] << endl;
        }

        int total_time = 0;
        for (int t : delays) {
            if (t == INT_MAX) return -1;
            total_time = max(total_time, t);
        }

        return total_time;
    }
};
