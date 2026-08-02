class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freqs;
        for (int num : nums) freqs[num]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto [num, freq] : freqs) buckets[freq].push_back(num);

        vector<int> result;
        int count = 0;
        int i = nums.size();
        while (count < k && i >= 0) {
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    result.push_back(num);
                    count++;
                    if (count == k) break;
                }
            }
            i--;
        }

        return result;
    }
};
