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

        vector<int> m(cost.size() + 1);
        m[0] = 0;
        m[1] = 0;

        for (int i = 2; i <= cost.size(); ++i) {
            m[i] = min(cost[i - 1] + m[i - 1], cost[i - 2] + m[i - 2]);
        }

        return m[cost.size()];

    }
};
