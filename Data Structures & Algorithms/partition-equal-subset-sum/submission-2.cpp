class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for (int i : nums) sum += i;
        if (sum % 2 != 0) return false;
        
        vector<bool> dp((sum / 2) + 1, false);
        dp[0] = true;

        for (int n : nums) {
            for (int i = sum / 2; i >= 0; --i) {
                dp[i] = dp[i] || (i - n >= 0 && dp[i - n]);
            }
        }

        return dp[sum / 2];
    }
};
