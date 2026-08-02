class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> prefixMaxes(height.size(), 0);
        vector<int> suffixMaxes(height.size(), 0);

        for (int i = 1; i < height.size(); ++i) {
            prefixMaxes[i] = max(prefixMaxes[i - 1], height[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; --i) {
            suffixMaxes[i] = max(suffixMaxes[i + 1], height[i + 1]);
        }

        int max_area = 0;
        for (int i = 0; i < height.size(); ++i) {
            max_area += max(min(prefixMaxes[i], suffixMaxes[i]) - height[i], 0);
        }

        return max_area;

        
    }
};
