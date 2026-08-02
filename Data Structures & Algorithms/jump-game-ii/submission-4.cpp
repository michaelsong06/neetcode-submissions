class Solution {
public:
    int jump(vector<int>& nums) {
        
        int furthest = 0;
        int current = 0;
        int jumps = 0;
        for (int i = 0; i < nums.size(); ++i) {
            furthest = max(furthest, i + nums[i]);
            if (current >= nums.size() - 1) return jumps;
            if (current == i) {
                jumps++;
                current = furthest;
            }
        }

        return jumps;

    }
};
