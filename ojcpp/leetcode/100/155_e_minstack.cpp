//
// Created by zhou rui on 4/4/18.
//

/*
 * https://leetcode.com/problems/min-stack/description/
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();  -> remove -3
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.



9:26 pm ->
 stack ->  -2/0/-3/
 MAX/-2/0/-2/-3 cool
 */

#include <codech/codech_def.h>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    int min_ = INT_MAX;
    stack<int> st_;
    MinStack() {

    }

    void push(int x) {
        if (x <= min_) {
            st_.push(min_);min_=x;
        }
        st_.push(x);
    }

    void pop() {
        if (st_.top() == min_) {
            st_.pop();
            min_ = st_.top();st_.pop();
        } else {
            st_.pop();
        }

    }

    int top() {
        return st_.top();
    }

    int getMin() {
        return min_;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */