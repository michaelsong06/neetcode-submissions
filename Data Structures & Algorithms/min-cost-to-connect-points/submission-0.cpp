class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        set<pair<int, int>> tree;
        int total_weight = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 
        // {a, {b, c}} signifies point {b, c} has key of a
        pq.push({0, {points[0][0], points[0][1]}});
        for (int i = 1; i < points.size(); ++i) {
            pq.push({INT_MAX, {points[i][0], points[i][1]}});
        }

        while (!pq.empty()) {
            auto [key, point] = pq.top(); pq.pop();

            if (tree.count(point)) continue;
            tree.insert(point);
            total_weight += key;

            for (vector<int>& _neighbour : points) {
                pair<int, int> neighbour = {_neighbour[0], _neighbour[1]};
                int manhattan = abs(neighbour.first - point.first) + abs(neighbour.second - point.second);
                pq.push({manhattan, neighbour});
            }
        }

        return total_weight;
                                                    
    }
};
