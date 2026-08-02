class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> prefixProds(nums.size(), 1);
        vector<int> suffixProds(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            prefixProds[i] = prefixProds[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            suffixProds[i] = suffixProds[i + 1] * nums[i + 1];
        }

        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = prefixProds[i] * suffixProds[i];
        }

        return result;


    }
};
