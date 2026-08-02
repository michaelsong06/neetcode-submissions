class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        bool added = false;

        while (i >= 0 && !added) {
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] == 0) i--;
            else added = true;
        }

        if (!added) digits.insert(digits.begin(), 1);

        return digits;
    }
};
