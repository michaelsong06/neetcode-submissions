class Solution {
public:
    bool canJump(vector<int>& nums) {

        vector<int> canReach(nums.size(), false);

        canReach[nums.size() - 1] = true;

        for (int i = nums.size() - 2; i >= 0; --i) {
            for (int j = i + 1; j <= i + nums[i]; ++j) {
                if (canReach[j]) {
                    canReach[i] = true;
                    break;
                }
            }
        }

        return canReach[0];
    }
};
