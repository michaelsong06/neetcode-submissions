class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int> maxes;

        deque<int> workingDeque;

        // Initialise the deque by brute force computing the max value
        // of the first window position (unfortunately have to as we 
        // know nothing about the values in nums yet)
        for (int i = 0; i < k; ++i) {
            while (!workingDeque.empty() && nums[i] > workingDeque.back()) {
                workingDeque.pop_back();
            }
            workingDeque.push_back(nums[i]);
        }
        maxes.push_back(workingDeque.front());

        // Now we can start our loop at the second window position
        for (int i = 1; i <= n - k; ++i) {
            if (workingDeque.front() == nums[i-1]) {
                workingDeque.pop_front();
            }
            while (!workingDeque.empty() && nums[i+k-1] > workingDeque.back()) {
                workingDeque.pop_back();
            }
            workingDeque.push_back(nums[i+k-1]);
            maxes.push_back(workingDeque.front());
        }

        return maxes;
    }
};
