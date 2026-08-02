class Solution {
    vector<vector<pair<int, int>>> graph; // graph[a] = {b, c}
                                          // means that from a to b costs c

    int cheapest = INT_MAX;

    void dfs(int current, int dest, int stops, int price, int k) {

        if (stops > k && current != dest) return;
        
        if (current == dest) {
            cheapest = min(cheapest, price);
            return;
        }

        for (auto [neighbour, cost] : graph[current]) {
            dfs(neighbour, dest, stops + 1, price + cost, k);
        }
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        graph.resize(n);
        for (vector<int>& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        dfs(src, dst, 0, 0, k);

        return (cheapest == INT_MAX) ? -1 : cheapest;

    }
};
