package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

// 求出所有在范围内的数字的bitwise and 运算
//例如, 5,6,7 -> 101 & 110 & 111
//思路 和最小值有关，最小值为0那么结果为0,
// 101 & 1000 - > 0
// 101 & 1100 ->  0
// 需要找出最小值和最大值，同时从最高位算起，有多少bit是相同的
//对于位数不一致的，每次向右移动一位，再比较
// 如果位数不一致，结果必然为0
public class Lc0201_bitandnumberrange extends BaseSolution {
    class Solution {
        public int rangeBitwiseAnd(int m, int n) {
            var count=0;
            while (m!=n) {
                m>>=1;
                n>>=1;
                count++;
            }
            return m<<count;
        }
    }
}
