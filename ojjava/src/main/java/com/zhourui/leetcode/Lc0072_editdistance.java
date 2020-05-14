package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;


import static java.lang.Integer.*;
//import static java.lang.Math.max;

//Insert a character
//        Delete a character
//        Replace a character
//        Example 1:
//
//        Input: word1 = "horse", word2 = "ros"
//        Output: 3
//        Explanation:
//        horse -> rorse (replace 'h' with 'r')
//        rorse -> rose (remove 'r')
//        rose -> ros (remove 'e')

// 和wordladder类似?并不需要wordladder那样做BFS，直接计算差异字符的个数即可。
// 但是AB/BC尽管有一个公共字符b，仍然需要2次变换，所以还要考虑位置
// LC1143 最长公共子序列(并不需要连续)类似，
// 如何判断位置？

// dp[i][j]表示编辑长度的话,和1143类似，
// dp[i][j] = dp[i-1][j-1]   if (A[i] == B[j]) 采用前面的编辑长度
// 如果不相等，看哪个编辑长度短,min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1// +1是最新的2个不相等，要增加一次编辑
// 最长公共子串并没有考虑dp[i-1][j-1]这种情况，因为这个必然是小的
// 初始条件： dp[0][j] = j and dp[i][0] = i //第二个字符为0的话，第一个字符编辑I次 可以变成第二个字符
// DP[0][0]=0

//递推公式出来了：
//        dp[i][j] =  dp[i-1][j-1]   if (A[i] == B[j])
//        or = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) +1;
// 参考返回最长公共子串的长度
// 问题转化为dp[0...i][0..j]是否存在公共字串
// 1.text1[i]==text2[j] && dp[i-1][j-1]存在公共字串
// 2.max(dp[i-1][j], dp[i][j-1]);



public class Lc0072_editdistance extends BaseSolution {
    class Solution {
        public int minDistance(String word1, String word2) {
            if (word1.isEmpty() ||word2.isEmpty()) {
                return max(word1.length(),word2.length());
            }
            int [][]dp = new int[word1.length()+1][word2.length()+1];
            //初始化
            for (int i=0;i<=word1.length();i++) {
                dp[i][0]=i;
            }
            for (int i=0;i<=word2.length();i++) {
                dp[0][i]=i;
            }

            for (int i=1;i<=word1.length();i++) {
                for (int j=1;j<=word2.length();j++) {
                    dp[i][j]= word1.charAt(i-1)==word2.charAt(j-1)?dp[i-1][j-1]:min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
            return dp[word1.length()][word2.length()];
        }


    }

    @Override
    public boolean test() {
        var slu=new Solution();
        var ret = true;
        ret &= slu.minDistance("distance","springbok")==9;
        ret &= slu.minDistance("","a")==1;
        ret &= slu.minDistance("horse","ros")==3;

        return ret;
    }
}
