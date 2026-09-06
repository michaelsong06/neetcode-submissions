class Solution {
private:
    int min_cost(vector<int>& cost, vector<int>& memo, int i) {
        if (i == 0 || i == 1) return 0;
        if (memo[i - 1] == -1) memo[i - 1] = min_cost(cost, memo, i - 1);
        if (memo[i - 2] == -1) memo[i - 2] = min_cost(cost, memo, i - 2);
        return min(cost[i - 1] + memo[i - 1], cost[i - 2] + memo[i - 2]);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        return min_cost(cost, memo, cost.size());
    }
};
