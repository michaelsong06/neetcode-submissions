class Solution {
public:
    int findMin(vector<int> &nums) {
        
        return binSearch(nums, 0, nums.size() - 1);

    }

    int binSearch(vector<int> &nums, int left, int right) {

        if (right <= left) return nums[0];

        int i = (right + left) / 2;
        cout << i << "\n";

        if (nums[i-1] > nums[i] && nums[i] < nums[i+1]) {
            return nums[i];
        } else {
            if (right - left == 1) {
                return min(nums[right], nums[left]);
            }
            return min(binSearch(nums, left, i), binSearch(nums, i, right));
        }

    }
};
