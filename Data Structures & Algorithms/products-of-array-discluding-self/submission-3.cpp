class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixes(n);
        vector<int> suffixes(n);

        prefixes[0] = 1;
        for (int i = 1; i < n; ++i) {
            prefixes[i] = nums[i - 1] * prefixes[i - 1];
        }

        suffixes[n-1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            suffixes[i] = nums[i + 1] * suffixes[i + 1];
        }

        vector<int> products(n);
        for (int i = 0; i < n; ++i) {
            products[i] = prefixes[i] * suffixes[i];
        }

        return products;
    }
};
