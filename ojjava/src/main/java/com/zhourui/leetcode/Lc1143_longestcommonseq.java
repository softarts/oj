package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import static java.lang.Math.max;

//问题转化为dp[0...i][0..j]是否存在公共字串
//        1.text1[i]==text2[j] && dp[i-1][j-1]存在公共字串
//        2.max(dp[i-1][j], dp[i][j-1]);
// [1,1],[1,2],[1,3],[1,4].... 都是为1
//第一种方式：
//        int a[][]={{1,2,3},{4,5,6}};
//                //第二种方式；
//                int[][] ints = new int[4][2];
//                ints[i][j] =__; //分别赋值
//                //第三种方式：第二维的长度可以动态申请
//
public class Lc1143_longestcommonseq extends BaseSolution {
    class Solution {
        public int longestCommonSubsequence(String text1, String text2) {
            int dp[][] = new int[1001][1001];
            for (int i=1;i<=text1.length();i++) {
                for (int j=1;j<=text2.length();j++) {//
                    dp[i][j] = text1.charAt(i-1)==text2.charAt(j-1)?dp[i-1][j-1]+1:max(dp[i][j-1],dp[i-1][j]);
                }
            }
            return dp[text1.length()][text2.length()];
        }
    }

    @Override
    public boolean test() {
        return super.test();
    }
}
