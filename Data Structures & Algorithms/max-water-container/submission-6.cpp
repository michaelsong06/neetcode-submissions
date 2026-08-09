class Solution {
public:
    int maxArea(vector<int>& heights) {

        int res = 0, n = heights.size();
        
        int l = 0, r = n - 1;

        while (l < r) {
            res = max(res, min(heights[l], heights[r]) * (r - l));
            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};
