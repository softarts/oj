package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Stack;

// 标准的使用stack
public class Lc0020_validparenthese extends BaseSolution {
    class Solution {
        public boolean isValid(String s) {
            Stack<Character> st = new Stack();
            for (int i=0;i<s.length();i++) {
                switch (s.charAt(i)) {
                    case '(':
                    case '[':
                    case '{':
                        st.push(s.charAt(i));
                        break;
                    case ')': if (!st.isEmpty() && st.peek()=='(') st.pop(); else return false;break;
                    case ']': if (!st.isEmpty() && st.peek()=='[') st.pop(); else return false;break;
                    case '}': if (!st.isEmpty() && st.peek()=='{') st.pop(); else return false;break;
                }
            }
            return (st.isEmpty());
        }
    }
}
