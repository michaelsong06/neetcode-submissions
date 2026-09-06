class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxdp = 1;
        int mindp = 1;
        int res = nums[0];

        for (int n : nums) {
            int temp = maxdp * n;
            maxdp = max(max(maxdp * n, mindp * n), n);
            mindp = min(min(temp, mindp * n), n); 
            res = max(res, maxdp);
        }

        return res;
    }
};
