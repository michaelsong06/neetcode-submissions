class Solution {
public:

    vector<string> output;

    void backtrack(string input, int n, int opens, int closes) {
        
        if (input.length() == 2*n) {
            output.push_back(input);
            return;
        }

        if (closes < opens && opens < n) {
            backtrack(input + '(', n, opens + 1, closes);
            backtrack(input + ')', n, opens, closes + 1);
        } else if (closes >= opens && opens < n) {
            backtrack(input + '(', n, opens + 1, closes);
        } else if (closes < opens && opens >= n) {
            backtrack(input + ')', n, opens, closes + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        
        backtrack("", n, 0, 0);

        return output;
    }
};
