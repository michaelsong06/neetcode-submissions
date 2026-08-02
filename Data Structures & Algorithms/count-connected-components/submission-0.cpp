class Solution {
private:
    void dfs(vector<vector<int>>& adj, vector<bool>& traversed, int current) {
        traversed[current] = true;
        for (int neighbour : adj[current]) {
            if (!traversed[neighbour]) dfs(adj, traversed, neighbour);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> traversed(n);
        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (!traversed[i]) {
                dfs(adj, traversed, i);
                c++;
            }
        }

        return c;
    }
};
