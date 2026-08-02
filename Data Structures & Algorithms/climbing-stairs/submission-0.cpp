class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> m(n + 1, 0);
        m[0] = 1;
        m[1] = 1;

        for (int i = 2; i <= n; ++i) {
            m[i] = m[i - 1] + m[i - 2];
        }

        return m[n];
    }
};
