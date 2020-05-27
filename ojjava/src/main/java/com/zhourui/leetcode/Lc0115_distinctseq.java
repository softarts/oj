package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;


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
//  ^  ^^
//babgbag
//    ^^^
//这题看起来就是那个最长公共序列
//但是问有多少做法
//dfs可行，但是TLE?
//问题转化为 [i][j]之间存在多少个长度为j的公共序列
//参考 1143和0072
// 直觉可以用backtrace
import static java.lang.Math.max;

public class Lc0115_distinctseq extends BaseSolution {

    class Solution {
        public int numDistinct(String s, String t) {
            // DP解法.
            // 能够用backtrace的基本也能用DP
            // dp[i][j] 表示i和j两个长度之间, t在s中可以找到多少次，
            // 递推关系
            //  t[j]!=s[i] ,dp[i][j]=dp[i-1][j] //因为要完全找到，所以只有这个，不会有什么[j-1]
            // t[j]==s[i]. dp[i][j] = dp[i-1][j](之前一位能找到的次数)+ dp[i-1][j-1]
            // (除开最后一个字符的匹配次数，因为最后一个字符匹配，所以加上这部分)
            int [][]dp = new int[s.length()+1][t.length()+1];

            //初始化
            for (int i=0;i<=s.length();i++) {
                dp[i][0]=1;
            }
            for (int i=0;i<=t.length();i++) {
                dp[0][i]=1;
            }


            for (int i=1;i<=s.length();i++) {
                for (int j=1;j<=t.length();j++) {
                    dp[i][j]= s.charAt(i-1)==t.charAt(j-1)?dp[i-1][j]+dp[i-1][j-1]:dp[i-1][j];
                }
            }
            return dp[s.length()][t.length()];
        }

        // 这个果然TLE
        int helper(int pos, String s, int tpos, String t) {
            if (pos>=s.length() && tpos<t.length()) {
                return 0;
            }

            if (tpos>=t.length()) {
                return 1;
            }
            int ret = 0;
            if (s.charAt(pos) == t.charAt(tpos)) {
                ret += helper(pos+1,s,tpos+1,t);
                ret += helper(pos+1,s,tpos,t);
            } else {
                ret += helper(pos+1,s,tpos,t);
            }
            return ret;
        }

        void helper0(String s, String t) {
            int ans = 0;
            int spos = 0,tpos=0;
            while (spos<s.length()) {
                if (s.charAt(spos)==t.charAt(tpos)) {
                    spos+=1;tpos+=1;
                } else {
                    spos+=1;
                }
            }

        }





    }

    @Override
    public boolean test() {
        var slu = new Solution();
        //System.out.println(slu.numDistinct("babgbag", "bag"));
        // 700531452
        var ret = slu.numDistinct("adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc",
        "bcddceeeebecbc");
        System.out.println(ret);
        return true;
        //return slu.numDistinct("babgbag", "bag")==5;
    }
}
