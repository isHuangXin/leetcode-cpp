//
// Created by huangxin on 1/16/22.
//

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    MinStack() {
        while (!stack1.empty())
            stack1.pop();
        while (!stack2.empty())
            stack2.pop();
    }

    void push(int x) {
        stack1.push(x);
        if (stack2.empty()||stack2.top() >=x)
            stack2.push(x);
    }

    void pop() {
        int top = stack1.top();
        stack1.pop();
        if(stack2.top()==top)
            stack2.pop();
    }

    int top() {
        return stack1.top();
    }

    int min() {
        return stack2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */