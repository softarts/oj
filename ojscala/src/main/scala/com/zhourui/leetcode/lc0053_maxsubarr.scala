package com.zhourui.leetcode

import scala.math.{abs, max}
import com.zhourui.codech.BaseExtension

package lc0053_maxsubarr {




  object Solution {
    def maxSubArray(nums: Array[Int]): Int = {
      var maxsum:Int=Int.MinValue
      nums.foldLeft(0) {
        case (a,b) => { // 第一次进入时,a=0
          val cursum = max(a+b,b)
          maxsum = max(maxsum, cursum)
          cursum
        }
      }
      return maxsum
    }
  }

  class Test extends BaseExtension {
    def init {
      val arr = Array(-2, 1, -3, 4, -1, 2, 1, -5,4)
      println(Solution.maxSubArray(arr) == 6)

    }
    val name = "053 max sub array"
  }
}



/*
[-2,1,-3,4,-1,2,1,-5,4]
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum = nums[0];
        int maxsum = cursum;

        for (int i=1;i<nums.size();i++) {
            cursum = max(cursum+nums[i],nums[i]);
            maxsum = max(maxsum, cursum);
        }
        return maxsum;
    }
};
 */