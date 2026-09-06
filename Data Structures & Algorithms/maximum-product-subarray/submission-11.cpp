class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxdp = 1;
        int mindp = 1;
        int res = nums[0];

        for (int n : nums) {
            int tempmax = max(max(maxdp * n, mindp * n), n);
            mindp = min(min(maxdp * n, mindp * n), n); 
            maxdp = tempmax;
            res = max(res, maxdp);
        }

        return res;
    }
};
