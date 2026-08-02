class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixes;
        vector<int> suffixes;

        for (int i = 0; i < nums.size(); ++i) {
            int product = 1;
            for (int j = 0; j < i; ++j) {
                product *= nums[j];
            }
            prefixes.push_back(product);
        }

        for (int i = nums.size() - 1; i >= 0; --i) {
            int product = 1;
            for (int j = nums.size() - 1; j > i; --j) {
                product *= nums[j];
            }
            suffixes.insert(suffixes.begin(), product);
        }

        vector<int> products;
        for (int i = 0; i < prefixes.size(); ++i) {
            products.push_back(prefixes[i] * suffixes[i]);
        }

        return products;
    }
};
