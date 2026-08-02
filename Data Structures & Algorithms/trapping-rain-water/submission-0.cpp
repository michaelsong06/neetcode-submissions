class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> prefixMaxes(height.size());
        vector<int> suffixMaxes(height.size());

        for (int i = 0; i < height.size(); ++i) {
            int prefixMax = 0;
            for (int j = 0; j < i; ++j) {
                prefixMax = max(prefixMax, height[j]);
            }
            prefixMaxes[i] = prefixMax;
        }

        for (int i = height.size() - 1; i >= 0; --i) {
            int suffixMax = 0;
            for (int j = height.size() - 1; j > i; --j) {
                suffixMax = max(suffixMax, height[j]);
            }
            suffixMaxes[i] = suffixMax;
        }

        vector<int> maxAtIndex(height.size());
        for (int i = 0; i < height.size(); ++i) {
            maxAtIndex[i] = max(min(prefixMaxes[i], suffixMaxes[i]) - height[i], 0);
        }

        for (int x : maxAtIndex) cout << x << " ";
        cout << "\n";

        int area = 0;
        for (int height : maxAtIndex) area += height;

        return area;
        
    }
};
