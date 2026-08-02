class Solution {
public:

    vector<vector<int>> output;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, {}, target, 0);
        return output;
    }

    void backtrack(vector<int>& nums, vector<int> combo, int target, int index) {
        
        int sum = 0;
        for (int n : combo) sum += n;

        if (sum > target) return;

        if (sum == target) {
            output.push_back(combo);
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            combo.push_back(nums[i]);
            backtrack(nums, combo, target, i);
            combo.pop_back();
        }
    }
};
