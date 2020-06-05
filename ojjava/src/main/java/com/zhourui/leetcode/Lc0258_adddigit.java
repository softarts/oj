package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

//O(1) 有点难
//38 -> 11->2，如果不需要loop 得到最后结果?
//0->0
//1~9 -> 1-9 =9
//10~18-> 1-9
//19~27 ->1-9
//28~36 ->1-9
//37
//46
//55
//64
//73
//82
//91
//100
//109
public class Lc0258_adddigit extends BaseSolution {
    class Solution {
        public int addDigits(int num) {
            return (num-1)%9+1;
        }
    }
}
