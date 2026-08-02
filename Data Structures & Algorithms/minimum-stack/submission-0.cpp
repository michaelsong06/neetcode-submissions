class MinStack {
private:
    vector<int> stack;
    vector<int> mins;
public:

    MinStack() {}
    
    void push(int val) {
        stack.push_back(val);
        if (mins.empty()) mins.push_back(val);
        else mins.push_back(min(mins.back(), val));
    }
    
    void pop() {
        int val = top();
        stack.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return mins.back();
    }
};
