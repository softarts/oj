package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;
import java.util.Base64;

//Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//Output: true
public class Lc0097_interleaving extends BaseSolution {
    // TLE
    class Solution0 {
        public boolean isInterleave(String s1, String s2, String s3) {
            if (s1.length()+s2.length()!=s3.length()) return false;
            return helper(s1,s2,s3,0,0,0);
        }

        boolean helper(String s1,String s2, String s3,int a1, int a2,int a3) {
            if (a3==s3.length()) return true;

            char b3 = s3.charAt(a3);
            if (a1<s1.length() && s1.charAt(a1)==b3) {
                if (helper(s1,s2,s3,a1+1,a2,a3+1)) {
                    return true;
                }
            }

            if (a2<s2.length() &&  s2.charAt(a2)==b3) {
                if (helper(s1,s2,s3,a1,a2+1,a3+1)) {
                    return true;
                }
            }
            return false;
        }
    }

    @Override
    public boolean test() {
        var slu=new Solution();
        return slu.isInterleave("aabcc","dbbca","aadbbcbcac")==true;
    }

    // backtrace TLE，只能考虑dp了
    //问题转化为dp[0...i][0..j]是否存在交积字符串,dp[1][1]表示s1和s2各出一个字符
    //s3[i+j]==s1[i] && dp[i-1][j]交积字符串
    //s3[i+j]==s2[j] && dp[i][j-1]交积字符串
    // 思路差不多，但是错在哪里？
    // 必须从s3的第二个开始，因为[1][1]意味着必须2个字符.同时需要对[1][xx]和[xx][1]进行边界初始化


    class Solution {
        public boolean isInterleave(String s1, String s2, String s3) {
            if (s1.length()+s2.length()!=s3.length()) return false;
            boolean[][]dp = new boolean[s1.length()+1][s2.length()+1];
            //初始化边界
            dp[0][0] = true;
            for (int i = 1; i <=s1.length() ; i++) {
                dp[i][0] = s3.charAt(i-1) == s1.charAt(i-1) ? dp[i-1][0]:false;
            }

            for (int i = 1; i <=s2.length() ; i++) {
                dp[0][i] = s3.charAt(i-1) == s2.charAt(i-1) ? dp[0][i-1]:false;
            }

            for (int i=1; i <=s1.length();i++) {
                for (int j=1;j<=s2.length();j++) {
                    //dp[i][j] = text1[i-1]==text2[j-1]?dp[i-1][j-1]+1:max(dp[i-1][j], dp[i][j-1]);
                    char b3=s3.charAt(i+j-1); // 必须从第二个开始，因为[1][1]意味着必须2个字符.
//                    var ret1= b3==s1.charAt(i-1)?dp[i-1][j]:false;
//                    var ret2= b3==s2.charAt(j-1)?dp[i][j-1]:false;
                    var ret1= b3==s1.charAt(i-1) && dp[i-1][j];
                    var ret2= b3==s2.charAt(j-1) && dp[i][j-1];

                    dp[i][j] = ret1||ret2;
                    System.out.println(String.format("dp[%s][%s]=%s",i,j,dp[i][j]));
                    //dp[i][j] = (b3==s1.charAt(i-1) && dp[i-1][j]) ||(b3==s2.charAt(j-1) && dp[i][j-1]);
                }
            }


            return dp[s1.length()][s2.length()];
        }


    }
}
