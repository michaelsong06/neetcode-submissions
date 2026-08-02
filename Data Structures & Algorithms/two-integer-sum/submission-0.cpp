class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> numMap;

        for (int i = 0; i < nums.size(); ++i) {
            int residual = target - nums[i];
            if (!numMap.count(residual)) {
                numMap[nums[i]] = i;
            } else {
                return {numMap[residual], i};
            }
        }
        return {};
    }
};
