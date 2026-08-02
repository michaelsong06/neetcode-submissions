class Solution {
public:
    bool isValid(string s) {

        unordered_set<char> opens = {'(','{','['};
        unordered_map<char, char> closes = {{')','('}, {'}','{'}, {']','['}};

        stack<char> myStack;

        for (char c : s) {
            if (opens.count(c)) {
                myStack.push(c);
            } else if (closes.count(c)) {
                if (myStack.empty() || myStack.top() != closes[c]) return false;
                myStack.pop();
            }
        }
        
        return myStack.empty();
    }
};
