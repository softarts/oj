package com.zhourui.leetcode;

import java.util.Stack;

// 思路
public class Lc0155_minstack {
    class MinStack {
        Stack<Integer> st = new Stack();
        int min_ = Integer.MAX_VALUE;
        /** initialize your data structure here. */
        public MinStack() {

        }

        public void push(int x) {
            if (x<=min_) {
                st.push(min_);min_=x;
            }
            st.push(x);
        }

        public void pop() {
            if (st.peek() == min_) {
                st.pop();
                min_ = st.peek();
                st.pop();
            } else {
                st.pop();
            }
        }

        public int top() {
            return st.peek();
        }

        public int getMin() {
            return min_;
        }
    }

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
}
