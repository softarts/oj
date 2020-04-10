package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Stack;

public class Lc0844_backspace extends BaseSolution {
    class Solution {
        public boolean backspaceCompare(String S, String T) {
            Stack<Character> stack0= new Stack(),stack1=new Stack();
            for (char c:S.toCharArray()) {
                if (c=='#') {
                    if (!stack0.empty()) stack0.pop();
                } else {
                    stack0.push(c);
                }
            }
            for (char c:T.toCharArray()) {
                if (c=='#') {
                    if (!stack1.empty()) stack1.pop();
                } else {
                    stack1.push(c);
                }
            }
            return stack1.equals(stack0);
        }
    }
}
