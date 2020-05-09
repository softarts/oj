package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

public class Lc0263_uglynumber extends BaseSolution {
    class Solution {
        public boolean isUgly(int num) {
            if (num<=0) return false;
            while (true) {
                while (num %2==0) {num=num/2;}
                while (num %3==0) {num=num/3;}
                while (num %5==0) {num=num/5;}
                if (num==1)
                    return true;
                else
                    return false;
            }

        }
    }
}
