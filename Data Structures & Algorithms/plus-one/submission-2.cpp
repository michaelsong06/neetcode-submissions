class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;

        while (i >= 0) {
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] == 0) i--;
            else return digits;
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }
};
