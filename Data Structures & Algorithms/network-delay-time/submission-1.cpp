class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n + 1); // adj[a] = {b, c} means a->c costs b
        for (vector<int>& edge : times) {
            adj[edge[0]].push_back({edge[2], edge[1]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (pair<int, int> f : adj[k]) pq.push(f);

        vector<int> delays(n + 1, INT_MAX);
        delays[k] = 0;
        delays[0] = 0; // 1-indexed nodes, so ignore 0
        
        while (!pq.empty()) {
            auto [delay, node] = pq.top(); pq.pop();

            if (delays[node] <= delay) continue;
            delays[node] = delay;

            for (auto [t, f] : adj[node]) pq.push({t + delay, f});
        }

        int total_time = 0;
        for (int t : delays) {
            if (t == INT_MAX) return -1;
            total_time = max(total_time, t);
        }

        return total_time;

        // BELLMAN FORD:

        // vector<int> delays(n + 1, INT_MAX);
        // delays[k] = 0;
        // delays[0] = 0;

        // for (int i = 0; i < n - 1; ++i) {
        //     vector<int> temp_delays = delays;

        //     for (vector<int>& edge : times) {
        //         int u = edge[0];
        //         int v = edge[1];
        //         int t = edge[2];

        //         if (delays[u] == INT_MAX) continue;
                
        //         if (delays[u] + t < temp_delays[v]) {
        //             temp_delays[v] = delays[u] + t;
        //         }
        //     }
        //     delays = temp_delays;
        // }

        // for (int i = 0; i < n + 1; ++i) {
        //     cout << i << ": " << delays[i] << endl;
        // }

        // int total_time = 0;
        // for (int t : delays) {
        //     if (t == INT_MAX) return -1;
        //     total_time = max(total_time, t);
        // }

        // return total_time;
    }
};
