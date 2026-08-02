class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int i = (l + r) / 2;
            if (nums[i] < nums[r]) r = i;
            else l = i + 1;
        }

        int minIndex = r;
        cout << minIndex << "\n";

        if (minIndex == 0) {
            l = 0;
            r = nums.size() - 1;
        } else {
            if (nums[0] < target) {
                l = 0;
                r = minIndex;
            } else if (nums[0] > target) {
                l = minIndex;
                r = nums.size() - 1;
            } else return 0;
        }

        

        while (l < r) {
            int i = (l + r) / 2;
            cout << i << " " << l << " " << r << "\n";
            if (nums[i] < target) l = i + 1;
            else r = i;
        }

        return (nums[l] == target) ? l : -1;
    }
};
