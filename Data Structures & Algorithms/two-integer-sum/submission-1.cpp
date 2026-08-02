class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> s;

        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i])) {
                return {s[nums[i]], i};
            } else {
                s[target - nums[i]] = i;
            }
        }

        return {};
    }
};
