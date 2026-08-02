class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max_sum = INT_MIN;
        int current = 0;

        for (int i = 0; i < nums.size(); ++i) {
            current += nums[i];
            max_sum = max(max_sum, current);
            if (current < 0) {
                current = 0;
            }
        }

        return max_sum;
    }
};
