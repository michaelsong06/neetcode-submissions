class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> pref(n, 1);

        for (int i = 1; i < n; ++i) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }
        int acc = 1;
        for (int i = n - 1; i >= 0; --i) {
            pref[i] *= acc;
            acc *= nums[i];
        }

        return pref;
    }
};
