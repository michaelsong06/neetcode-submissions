class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();

        unordered_map<int, int> f;
        for (int i : nums) {
            f[i]++;
        }

        vector<vector<int>> buckets(n + 1, vector<int>());
        for (const auto& [i, freq] : f) {
            buckets[freq].push_back(i);
        }

        vector<int> res;
        for (int freq = n; freq >= 0; --freq) {
            for (int i : buckets[freq]) {
                res.push_back(i);
                if (res.size() >= k) {
                    return res;
                }
            }
        }
        return res;
    }
};
