class Solution {
private:
    int sum_of_sqs(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        
        int slow = n, fast = n;

        while (fast != 1) {
            slow = sum_of_sqs(slow);
            cout << slow << endl;
            fast = sum_of_sqs(sum_of_sqs(fast));

            if (slow == fast && slow != 1) return false;
        }

        return true;
    }
};
