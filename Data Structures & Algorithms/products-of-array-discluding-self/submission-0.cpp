class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products;

        for (int i = 0; i < nums.size(); ++i) {
            int product = 1;
            for (int j = 0; j < nums.size(); ++j) {
                if (j != i) {
                    product *= nums[j];
                }
            }
            products.push_back(product);
        }
        return products;
    }
};
