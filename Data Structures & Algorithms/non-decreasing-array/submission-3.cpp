class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        int n = nums.size();

        if (n <= 1) return true;

        for (int i = 0; i < n; ++i) {
            bool non_decreasing = true;
            int curr = 0;

            for (int j = 0; j < n; ++j) {
                if (j == i) continue;

                if (j > 0 && nums[j] < curr) {
                    non_decreasing = false;
                    break;
                }

                curr = nums[j];
            }

            if (non_decreasing) return true;
        }

        return false;
    }
};