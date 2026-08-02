class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<char> operators = {'+', '-', '*', '/'};

        stack<string> stack;

        for (string tok : tokens) {
            if (isdigit(tok[0]) || tok[0] == '-' && isdigit(tok[1])) {
                stack.push(tok);
            } else if (tok.length() == 1 && operators.count(tok[0])) {
                int op2 = stoi(stack.top());
                stack.pop();
                int op1 = stoi(stack.top());
                stack.pop();
                switch (tok[0]) {
                    case '+':
                        stack.push(to_string(op1 + op2));
                        break;
                    case '-':
                        stack.push(to_string(op1 - op2));
                        break;
                    case '*':
                        stack.push(to_string(op1 * op2));
                        break;
                    case '/':
                        stack.push(to_string(op1 / op2));
                        break;
                    default:
                        return -1;
                }
            }
        }

        if (stack.size() == 1) {
            return stoi(stack.top());
        } else {
            return -1;
        }
    }
};
