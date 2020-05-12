package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;
import java.util.Collection;

//判断两个字符串是不是scramble
//Input: s1 = "great", s2 = "rgeat"
//Output: true
//Input: s1 = "abcde", s2 = "caebd"
//Output: false

//居然没有sort string 的做法
//char []c1=s1.toCharArray();
//char []c2=s2.toCharArray();
//Arrays.sort(c1);
//Arrays.sort(c2);
//if (!c1.equals(c2)) return false; // rgeat vs great

//hard 思路
// 对每个位置进行测试，前部和后部交叉对比，就是java做起来有点累
//https://www.linkedin.com/learning/nail-your-c-plus-plus-interview/what-you-should-know
public class Lc0087_scramblestring extends BaseSolution {
    class Solution {
        public boolean isScramble(String s1, String s2) {
            if (s1.length()!=s2.length()) return false;
        }


        boolean helper(String s1, String s2) {
            if (s1.equals(s2)) return true;

            if (new StringBuilder(s1).reverse().toString().equals(s2)) return true;

            for (int i=0;i<s1.length();i++) {
                String a1=s1.substring(0,i);
                String a2=s1.substring(i);
                String b1=s2.substring(0,i);
                String b2=s2.substring(i);

                if (helper(a1,b1) && helper(a2,b2))
                    return true;
            }
            return false;

        }
    }
}
