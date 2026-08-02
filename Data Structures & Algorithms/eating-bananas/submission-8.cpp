class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ub = *max_element(piles.begin(), piles.end());

        if (h == piles.size()) return ub;

        int l = 1, r = ub;
        while (l < r) {
            int mid = (l + r) / 2;
            long long time_needed = 0;
            for (int pile : piles) {
                time_needed += (pile + mid - 1) / mid;
            }
            if (time_needed <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return r;

    }
};
