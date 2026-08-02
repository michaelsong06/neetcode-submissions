class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> maxes;

        int l = 0;
        int r = k - 1;

        while (r < nums.size()) {
            int currentMax = INT_MIN;
            for (int i = l; i <= r; ++i) {
                currentMax = max(nums[i], currentMax);
            }
            maxes.push_back(currentMax);
            l++;
            r++;
        }

        return maxes;
    }
};
