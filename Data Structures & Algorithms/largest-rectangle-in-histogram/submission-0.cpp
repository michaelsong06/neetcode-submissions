class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int max_area = 0;

        for (int i = 0; i < n; ++i) {
            int this_min_height = INT_MAX;
            for (int j = i; j < n; ++j) {
                this_min_height = min(this_min_height, heights[j]);
                max_area = max(max_area, this_min_height * (j - i + 1));
            }
        }

        return max_area;
    }
};
