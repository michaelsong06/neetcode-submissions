class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {

            int i = (l + r) / 2;

            if (nums[i] < nums[r]) r = i;
            else l = i + 1;
            
        }

        return nums[l];

    }
};
