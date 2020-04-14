package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;

//
public class Lc0005_longestpalindromic extends BaseSolution {
    class Solution {
        public String longestPalindrome(String s) {
            if (s.isEmpty()) return "";
            boolean dp[][]= new boolean[1000][1000];
            //Arrays.setAll(dp,p->false);  //必须为false
            for (int i=0;i<1000;i++) {
                for (int j=0;j<1000;j++) {
                    dp[i][j]=false;
                }
            }


            int maxLen = 1;
            int start = 0;
            for (int i=0;i<s.length();i++) {
                dp[i][i] = true;
                for (int j=0;j<i;j++) {
                    //2种情况，前者是相邻字符相等，后者是子字串为回文
                    dp[j][i] = (i-j==1 && s.charAt(j)==s.charAt(i))|| (dp[j+1][i-1] && s.charAt(j)==s.charAt(i)) ;
                    if (dp[j][i] && maxLen<(i-j+1)) {
                        maxLen = i-j+1;
                        start=j;
                    }
                }
            }
            return s.substring(start,start+maxLen);
        }
    }
    @Override
    public boolean test() {
        boolean ret = true;
        {
            ret &= new Solution().longestPalindrome("")=="";
        }
        return ret;
    }

    @Override
    public String name() {return "0005 longest palindromic";}
}
