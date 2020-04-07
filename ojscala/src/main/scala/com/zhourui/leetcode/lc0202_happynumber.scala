package com.zhourui.leetcode

package lc0202_happynumber {
  object Solution {
    def isHappy(n: Int): Boolean = {
      def next(x:Int): Int ={
        x.toString().map(e=> (e-'0')*(e-'0')).sum
      }

      def solve(x:Int, m:Set[Int]): Boolean = x match {
        case 1 => return true
        case x if m.contains(x) =>return false
        case x =>solve(next(x), m+x)
      }
      solve(n, Set[Int]())
    }
  }
}
