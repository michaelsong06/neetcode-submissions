class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (l == i) l++;
                if (r == i) r--;

                if (nums[l] + nums[r] + nums[i] < 0) {
                    l++;
                    while (nums[l] == nums[l - 1]) l++;
                } else if (nums[l] + nums[r] + nums[i] > 0) {
                    r--;
                    while (nums[r] == nums[r + 1]) r--;
                } else {
                    result.push_back({nums[l], nums[r], nums[i]});
                    l++; r--;
                    while (nums[l] == nums[l - 1]) l++;
                    while (nums[r] == nums[r + 1]) r--;
                }
            }
        }

        return result;
    }
};
