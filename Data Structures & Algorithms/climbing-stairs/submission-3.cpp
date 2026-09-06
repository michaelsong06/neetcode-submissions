class Solution {
public:
    int climbStairs(int n) {
        
        int temp1 = 1;
        int temp2 = 1;
        int res = 1;

        for (int i = 2; i <= n; ++i) {
            res = temp1 + temp2;
            temp1 = temp2;
            temp2 = res;
        }

        return res;
    }
};
