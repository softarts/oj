package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;
import java.util.Collection;

//判断两个字符串是不是scramble
//Input: s1 = "great", s2 = "rgeat"
//Output: true
//Input: s1 = "abcde", s2 = "caebd"
//Output: false



//hard 思路
// 对每个位置进行测试，前部和后部交叉对比，就是java做起来有点累
//https://www.linkedin.com/learning/nail-your-c-plus-plus-interview/what-you-should-know

public class Lc0087_scramblestring extends BaseSolution {
    class Solution {
        public boolean isScramble(String s1, String s2) {
            return helper(s1,s2);
        }


        boolean helper(String s1, String s2) {
            if (s1.length()!=s2.length()) {
                return false;
            }
            if (s1.length()==0) return true;
            //reverse
            String s1a = new StringBuilder(s1).reverse().toString();
            if (s1.equals(s2) || s1a.equals(s2)) return true;

            //居然没有sort string 的做法
            char []s1c=s1.toCharArray();
            char []s2c=s2.toCharArray();
            Arrays.sort(s1c);
            Arrays.sort(s2c);
            //当比较两个数组的值的时候，需要使用Arrays类中的equals()方法。
            if (!Arrays.equals(s1c,s2c)) {
                return false; // rgeat vs great
            }

            int n = s1.length();
            for (int i=1;i<n;i++) {
                String b0=s1.substring(0,i);
                String b1=s1.substring(i);

                String c0=s2.substring(0,i);
                String c1=s2.substring(i);
                String c2=s2.substring(n-i);
                String c3=s2.substring(0,n-i);

                if ((helper(b0,c0) && helper(b1,c1)) || (helper(b0,c2) && helper(b1,c3)))
                    return true;
            }
            return false;
        }
    }

    @Override
    public boolean test() {
        return new Solution().isScramble("great","rgeat")==true;
    }
}
