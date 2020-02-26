package com.zhourui.leetcode
import scala.util.control.Breaks._
import scala.collection.mutable.Stack

package lc0039_combinationsum {
  object Solution {
    def combinationSum(candidates: Array[Int], target: Int): List[List[Int]] = {
      var arr = candidates
      scala.util.Sorting.quickSort(arr)
      var ans = Vector[List[Int]]()
      var subset  = Stack[Int]()

      def helper(nums:Array[Int], start:Int, rest:Int): Unit = {
        if (rest == 0) {
          ans = ans :+ subset.toList
          return
        }
        breakable {
          for (i<- start until nums.length) {
            if (rest>=nums(i)) {
              subset.push(nums(i))
              helper(nums,i,rest-nums(i))
              subset.pop
            } else {
              break()
            }
          }
        }
      }
      helper(arr,0,target)
      ans.toList
    }
  }
}

