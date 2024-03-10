class MinStack
{
public:
    vector<pair<int, int>> minStack;
    MinStack() {}

    void push(int val)
    {
        if (minStack.empty())
        {
            minStack.push_back({val, val});
        }
        else
        {
            int minValue = min(val, minStack.back().second);
            minStack.push_back({val, minValue});
        }
    }

    void pop() { minStack.pop_back(); }

    int top() { return minStack.back().first; }

    int getMin() { return minStack.back().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */