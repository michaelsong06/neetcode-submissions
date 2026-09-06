class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> maxdp(n);
        maxdp[0] = nums[0];
        vector<int> mindp(n);
        mindp[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) {
                maxdp[i] = (maxdp[i-1] > 0) ? maxdp[i-1] * nums[i] : nums[i];
                mindp[i] = (mindp[i-1] <= 0) ? mindp[i-1] * nums[i] : nums[i];
            } else {
                maxdp[i] = (mindp[i-1] <= 0) ? mindp[i-1] * nums[i] : nums[i];
                mindp[i] = (maxdp[i-1] > 0) ? maxdp[i-1] * nums[i] : nums[i];
            }
        }

        int res = INT_MIN;
        for (int i : maxdp) {
            res = max(i, res);
        }
        return res;
    }
};
