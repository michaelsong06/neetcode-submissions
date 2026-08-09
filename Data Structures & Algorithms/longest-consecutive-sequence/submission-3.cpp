class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        
        unordered_set<int> s(nums.begin(), nums.end());

        int res = 0;
        for (int i : nums) {

            if (!s.count(i - 1)) {
                int seq_length = 0;
                for (int j = i; j < i + n; ++j) {
                    if (!s.count(j)) break;
                    seq_length++;
                }
                res = max(res, seq_length);
            }
        }

        return res;
    }
};
