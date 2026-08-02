class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> output(n + 1);

        for (int i = 0; i <= n; ++i) {
            int weight = 0;
            for (int j = 0; j < 10; ++j) {
                if (((1 << j) & i)) weight++;
            }
            output[i] = weight;
        }

        return output;
    }
};
