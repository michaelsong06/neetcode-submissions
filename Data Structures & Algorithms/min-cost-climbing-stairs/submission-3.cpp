class Solution {
private:

    vector<int> memo;

    int recurse(vector<int>& cost, int current) {

        if (memo[current] != -1) return memo[current];

        if (current >= cost.size()) return 0;

        int added_cost = 0;
        if (current < cost.size()) {
            added_cost = cost[current] + min(recurse(cost, current + 1), recurse(cost, current + 2));
        }
        
        memo[current] = added_cost;

        return added_cost;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {

        memo.resize(cost.size() + 1);
        for (int i = 0; i < cost.size() + 1; ++i) memo[i] = -1;
        
        return min(recurse(cost, 0), recurse(cost, 1));

    }
};
