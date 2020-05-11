package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import static java.lang.Math.max;

public class Lc1143_longestcommonsequence extends BaseSolution {
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
}
