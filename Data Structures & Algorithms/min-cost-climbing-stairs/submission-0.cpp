class Solution {
private:
    int recurse(vector<int>& cost, int current) {
        if (current == cost.size()) return 0;

        int added_cost = INT_MAX;
        if (current + 1 <= cost.size()) {
            added_cost = min(added_cost, recurse(cost, current + 1));
        }
        if (current + 2 <= cost.size()) {
            added_cost = min(added_cost, recurse(cost, current + 2));
        }
        added_cost += cost[current];
        return added_cost;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        return min(recurse(cost, 0), recurse(cost, 1));

    }
};
