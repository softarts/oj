package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

//不允许用字符串中转
public class Lc0009_ispalindrome extends BaseSolution {
    class Solution {
        public boolean isPalindrome(int x) {
            if (x<0) return false;
            if (x==0) return true;
            var r=0;
            while (x>0) {
                r=r*10+x%10;
                x=x/10;
            }
            return r==x;
        }
    }
}
