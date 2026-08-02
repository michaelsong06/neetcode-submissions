class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> pref(n, 1);

        for (int i = 1; i < n; ++i) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }
        int acc = 1;
        for (int i = n - 2; i >= 0; --i) {
            acc *= nums[i + 1];
            pref[i] *= acc;
        }

        return pref;
    }
};
