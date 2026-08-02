class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> numSet(nums.begin(), nums.end());

        int maxLength = 0;

        for (int num : nums) {
            if (numSet.count(num - 1)) continue;
            int curr = num;
            int length = 0;
            while (numSet.count(curr)) {
                curr++;
                length++;
                maxLength = max(maxLength, length);
            }
        }

        return maxLength;

    }
};
