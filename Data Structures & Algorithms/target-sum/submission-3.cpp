class Solution {
private:
    vector<unordered_map<int, int>> memo;

    int backtrack(vector<int>& nums, int target, int current, int i) {

        if (memo[i].count(current)) return memo[i][current];

        int res;
        if (i == 0) {
            res = target == current;
        } else {
            res = backtrack(nums, target, current + nums[i-1], i - 1) + backtrack(nums, target, current - nums[i-1], i - 1);
        }
        memo[i][current] = res;
        
        return res;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        memo.resize(n + 1);

        return backtrack(nums, target, 0, n);

    }
};
