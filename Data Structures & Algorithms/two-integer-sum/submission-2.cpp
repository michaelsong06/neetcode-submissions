class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        unordered_map<int, int> s;
        for (int i = 0; i < n; ++i) {
            if (s.count(target - nums[i])) {
                return {s[target - nums[i]], i};
            }
            s[nums[i]] = i;
        }
        return {};
    }
};
