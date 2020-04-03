package com.zhourui.leetcode

package lc0136_singlenumber {
  object Solution {
    def singleNumber(nums: Array[Int]): Int = {
      val ret = nums.foldLeft(0) ( _ ^ _)
      return ret

    }
  }

}
