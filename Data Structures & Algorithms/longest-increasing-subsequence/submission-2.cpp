class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        int res = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = max(dp[i], (nums[j] < nums[i]) ? dp[j] + 1 : 1);
            }
            res = max(res, dp[i]);
        }

        return res;


        
        /*
        LIS(i) = 
            max{j<-[0..i-1]}((nums[j] < nums[i]) ? LIS(j) + 1 : 1)
        */
    }
};
