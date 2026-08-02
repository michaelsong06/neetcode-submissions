class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        // brute force solution:

        int n = temperatures.size();

        vector<int> output(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (temperatures[j] > temperatures[i]) {
                    output[i] = j - i;
                    break;
                }
            }
        }

        return output;

        
    }
};
