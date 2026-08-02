class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        // Generate count map where each number maps to its frequency
        for (int num: nums) {
            count[num]++;
        }

        // Flip this count map so each frequency maps to a list of numbers
        for (const auto& pair: count) {
            freq[pair.second].push_back(pair.first);
        }

        vector<int> sol;
        // Reverse this frequency list
        for (int i = freq.size() - 1; i >= 0; --i) {
            for (int n : freq[i]) {
                sol.push_back(n);
                if (sol.size() == k) {
                    return sol;
                }
            }
        }
        return sol;
       


    }
};
