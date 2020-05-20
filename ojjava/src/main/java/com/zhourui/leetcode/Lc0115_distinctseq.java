package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import static java.lang.Integer.min;


//Input: S = "babgbag", T = "bag"
//Output: 5
//Explanation:
//As shown below, there are 5 ways you can generate "bag" from S.
//(The caret symbol ^ means the chosen letters)
//
//babgbag
//^^ ^
//babgbag
//^^    ^
//babgbag
//^    ^^
//babgbag
//^  ^^
//babgbag
//^^^
//这题看起来就是那个最长公共序列
//但是问有多少做法
//dfs可行，但是TLE?
//问题转化为 [i][j]之间存在多少个长度为j的公共序列
//参考 1143和0072
public class Lc0115_distinctseq extends BaseSolution {
    class Solution {
        public int numDistinct(String s, String t) {
            int [][]dp = new int[s.length()+1][t.length()+1];

            //初始化
            for (int i=0;i<=s.length();i++) {
                dp[i][0]=0;
            }
            for (int i=0;i<=t.length();i++) {
                dp[0][i]=0;
            }

            for (int i=1;i<=s.length();i++) {
                for (int j=1;j<=t.length();j++) {

                    dp[i][j]= s.charAt(i-1)==t.charAt(j-1)?dp[i-1][j-1]:0
                            //min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }

        }
    }
}
