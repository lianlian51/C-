class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        dataStack.push(x); // 数据栈必定入栈操作

        // 最小栈①栈中没有元素 ②要出入的元素小于最小栈栈顶元素
        if(minstack.empty() || x <= minstack.top())
            minstack.push(x);
    }
    
    void pop() {
        if(dataStack.top() == minstack.top())
            minstack.pop();
        dataStack.pop();
    }
    
    int top() {
        // 返回数据栈栈顶元素
        return dataStack.top();
    }
    
    int getMin() {
        // 返回最小栈栈顶元素
        return minstack.top();
    }

private:
    stack<int> dataStack; // 保存数据的栈
    stack<int> minstack;  // 存放栈中最小值
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
