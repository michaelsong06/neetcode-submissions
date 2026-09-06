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

        int n = cost.size();
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; ++i) {
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }

        return dp[n];
    }
};
