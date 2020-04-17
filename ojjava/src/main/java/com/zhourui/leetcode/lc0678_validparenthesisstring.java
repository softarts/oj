package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

// (*)) true,因为*可以看作任意字符/空字符
// stack 很难处理，因为*可以代表3个不同的字符，还是从count上着手
// 极端情况, )很多， 需要把*看作(，假如*+( 都不够，那么无效。大于无问题，因为*可以看作是空字符串
// 极端情况, (很多， 需要把*看作)，假如*+) 都不够，那么无效。大于无问题，因为*可以看作是空字符串
//如果两者的差额小于*的数字，那么就没有任何问题。但是必须判断以下一点:
//注意这种情况  ())( 仍然是无效的，因为括号先无法匹配了。
//总结，对于此类问题， 计数很重要

public class lc0678_validparenthesisstring extends BaseSolution {
    class Solution {
        public boolean checkValidString(String s) {
            int count=0;
            for (int i=0;i<s.length();i++) {
                switch (s.charAt(i)) {
                    case '*':
                        count++;
                        break;
                    case '(':
                        count++;
                        break;
                    case ')':
                        count--;if (count<0) return false;
                        break;
                }
            }
            count = 0;
            for (int i=s.length()-1;i>=0;i--) {
                switch (s.charAt(i)) {
                    case '*':
                        count++;
                        break;
                    case '(':
                        count--;if (count<0) return false;
                        break;
                    case ')':
                        count++;
                        break;
                }
            }

            return true;
        }
    }
}
