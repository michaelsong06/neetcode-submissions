class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        set<int> tree;
        int total_weight = 0;

        vector<int> minDist(points.size(), INT_MAX);
        minDist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        // {a, b} signifies points[b] has weight a
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [weight, p_index] = pq.top(); pq.pop();

            if (tree.count(p_index)) continue;
            tree.insert(p_index);
            total_weight += weight;

            for (int i = 0; i < points.size(); ++i) {
                if (i == p_index) continue;
                vector<int> neighbour = points[i];
                int manhattan = abs(neighbour[0] - points[p_index][0]) + abs(neighbour[1] - points[p_index][1]);
                if (manhattan < minDist[i]) {
                    minDist[i] = manhattan;
                    pq.push({manhattan, i});
                }
            }
        }

        return total_weight;
                                                    
    }
};
