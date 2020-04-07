package com.zhourui.leetcode

package lc0283_movezero {
  object Solution {
    def moveZeroes(nums: Array[Int]): Unit = {
//      nums.foldLeft(0) {
//        case (w,b) => {
//          if (b!=0) {
//            nums(w) = b
//
//            w+1
//          } else w
//        }
//      }

      nums.indices.foldLeft(0) {
        case (acc, e) => {
          if (nums(e)!=0) {
            val tmp = nums(e)
            nums(e) = nums(acc)
            nums(acc) = tmp
            acc+1
          } else acc
        }
      }
    }
  }
}

/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int w = 0;
        for (int i = 0; i< nums.size(); i++) {
            if (nums[i]!=0) {
                swap(nums[w++], nums[i]);
            }
        }
    }
};
 */
