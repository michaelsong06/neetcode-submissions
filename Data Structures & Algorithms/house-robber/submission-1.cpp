class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> m(nums.size(), 0);
        m[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            m[i] = max(m[i - 1], m[i - 2] + nums[i]);
        }

        return m[nums.size() - 1];
    }
};
