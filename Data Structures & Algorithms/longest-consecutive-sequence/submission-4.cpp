class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        
        unordered_set<int> s(nums.begin(), nums.end());

        int res = 0;
        for (int i : nums) {

            if (!s.count(i - 1)) {
                int seq_length = 0;
                int j = i;
                while (s.count(j)) {
                    seq_length++;
                    j++;
                }
                res = max(res, seq_length);
            }
        }

        return res;
    }
};
