class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int max_area = 0;

        stack<pair<int, int>> stack; // {index, height}

        for (int i = 0; i < n; ++i) {
            int index = i;
            while (!stack.empty() && heights[i] < stack.top().second) {
                auto [top_index, top_height] = stack.top();
                max_area = max(max_area, top_height * (i - top_index));
                stack.pop();
                index = top_index;
            }
            stack.push({index, heights[i]});
        }
        
        while (!stack.empty()) {
            auto [top_index, top_height] = stack.top();
            max_area = max(max_area, top_height * (n - top_index));
            stack.pop();
        }

        return max_area;
    }
};
