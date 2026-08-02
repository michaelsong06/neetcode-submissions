class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();

        int median_index = (n + m) / 2;

        bool even = (n + m) % 2 == 0;

        int p1 = 0;
        int p2 = 0;
        int count = 0;
        int current;
        int prev;
        while (count <= median_index) {
            prev = current;
            if (p1 < n && (p2 >= m || nums1[p1] < nums2[p2])) {
                current = nums1[p1];
                p1++;
            } else {
                current = nums2[p2];
                p2++;
            }
            count++;
        }

        double median;
        if (!even) median = current;
        else median = (prev + current) / 2.0;

        return median;
    }
};
