class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Duplicate nums but make it a set instead for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        // Initialise tracker for longest sequence
        int longest = 0;

        for (int num : numSet) {
            // If num - 1 is not in the set, start counting from here
            if (!numSet.count(num - 1)) {
                int length = 1;
                // For every number greater than this number by 1, add 1 to it again
                // This allows us to count up in the sequence starting from num
                while (numSet.count(num + length)) {
                    length++;
                }
                // Once we have reached a number s.t. num + length is not in the set,
                // This means the end of the consecutive sequence has been reached
                // So we now take the current value of length to be the length
                // of the consecutive sequence we just counted
                longest = max(longest, length);
            }
        }
        
        return longest;
    }
};
