class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        set<int> numSet(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size(); ++i) {
            if (!numSet.count(i)) return i;
        }

        return -1;
    }
};
