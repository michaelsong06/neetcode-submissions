class Solution {
private:
    int dp_f(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
    }
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);
        return max(dp_f(nums1), dp_f(nums2));
    }
};
