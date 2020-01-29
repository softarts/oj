package com.zhourui.leetcode
import com.zhourui.codech.BaseExtension

//问题转化为dp[0...i][0..j]是否存在公共字串
//1.text1[i]==text2[j] && dp[i-1][j-1]存在公共字串
//2.否则从已有的dp中选择最大值 max(dp[i-1][j], dp[i][j-1]);
package lc1143{



  object Solution {
    def longestCommonSubsequence(text1: String, text2: String): Int = {
      val m = text1.length
      val n = text2.length
      //val dp = Array.ofDim[Int](1001,1001)
      val dp = Array.fill(1001,1001)(0)
      for (i<- 1 to m) { // must have space?
        for (j<- 1 to n) {
          dp(i)(j) = if (text1(i-1)== text2(j-1)) dp(i-1)(j-1)+1 else Math.max(dp(i-1)(j),dp(i)(j-1))
        }
      }
      dp(m)(n)
    }
  }

  class Test extends BaseExtension {
    def init {
      println(Solution.longestCommonSubsequence("abcde", "ace") == 3)
    }
    val name = "1143 Longest common sequence"
  }
}
