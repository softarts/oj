package com.zhourui.leetcode
import com.zhourui.codech._

package lc003 {
  object Solution {
    //s.zipWithIndex.foreach(println) // =>tuple
    //   def foldLeft[B](z: B)(op: (B, A) => B): B = {
    def lengthOfLongestSubstring(s: String): Int = {
      s.zipWithIndex.foldLeft((0, -1, Map[Char, Int]())) {
        case ((len, start_pos, map), (char, i)) => {
          // 初始值len=0,start_pos=-1,map为空; case A,B; 前者为累加值，后者为index
          // 如果char不存在,last_pos=-1,更新map中的idx,len=i-start_pos
          // 如果last_pos已存在,例如abca,第一个a为0,第二个a为3,则len=3-0,跟新start_pos
          val last_pos = map.getOrElse(char, -1)
          if (last_pos >= start_pos) (len.max(i - last_pos), last_pos, map + (char -> i))
          else (len.max(i - start_pos), start_pos, map + (char -> i))
        }
      }._1
    }
  }

  class Test extends BaseExtension {
    def init {
      println(Solution.lengthOfLongestSubstring("abcabcbb")==3)
    }
    val name = "003 Longest Non repeat str"
  }
}

