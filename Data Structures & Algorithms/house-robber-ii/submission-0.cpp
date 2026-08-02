class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];
        
        vector<int> m1(nums.size() - 1, 0);
        m1[0] = nums[0];
        m1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() - 1; ++i) {
            m1[i] = max(m1[i - 1], m1[i - 2] + nums[i]);
        }

        vector<int> m2(nums.size() - 1, 0);
        m2[0] = nums[1];
        m2[1] = max(nums[1], nums[2]);
        for (int i = 2; i < nums.size() - 1; ++i) {
            m2[i] = max(m2[i - 1], m2[i - 2] + nums[i + 1]);
        }

        return max(m1[nums.size() - 2], m2[nums.size() - 2]);

    }
};
