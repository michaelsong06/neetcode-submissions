class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int target = 0;
        for (int i = 0; i <= n; ++i) {
            target ^= i;
        }

        for (int num : nums) {
            target ^= num;
        }

        return target;
    }
};
