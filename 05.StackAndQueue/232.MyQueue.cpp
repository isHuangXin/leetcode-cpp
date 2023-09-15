// Problem: 232.用栈实现队列
// Link: https://leetcode.cn/problems/implement-queue-using-stacks/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;

    void in2out() {
        while(!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if(outStack.empty()) {
            in2out();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }
    
    int peek() {
        if(outStack.empty()) {
            in2out();
        }
        int x = outStack.top();
        return x;
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
        // return (outStack.empty() && inStack.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */