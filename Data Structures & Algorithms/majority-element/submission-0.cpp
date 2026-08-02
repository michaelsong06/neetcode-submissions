class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int current = nums[0];
        int count = 0;

        for (int num : nums) {
            if (num == current) count++;
            else {
                count--;
                if (count == 0) {
                    current = num;
                    count++;
                }
            }
        }

        return current;
    }
};