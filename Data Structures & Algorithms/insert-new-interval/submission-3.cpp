class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int newStart = newInterval[0], newEnd = newInterval[1];

        vector<vector<int>> mergedIntervals;

        int n = intervals.size();

        for (int i = 0; i < n; ++i) {
            int start = intervals[i][0], end = intervals[i][1];

            if (end < newStart) {
                mergedIntervals.push_back(intervals[i]);
            }

            else if (newEnd < start) {
                mergedIntervals.push_back({newStart, newEnd});

                for (int j = i; j < n; ++j) {
                    mergedIntervals.push_back(intervals[j]);
                }

                return mergedIntervals;
            }

            else {
                newStart = min(newStart, start);
                newEnd = max(newEnd, end);
            }
        }

        // Handle remaining merged interval (including insertion at the end)
        mergedIntervals.push_back({newStart, newEnd});

        return mergedIntervals;
    }
};