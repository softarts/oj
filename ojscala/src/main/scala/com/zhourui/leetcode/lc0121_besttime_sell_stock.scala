package com.zhourui.leetcode

import com.zhourui.codech._
import scala.math.{min,max}

//[7,1,5,3,6,4] -> 6-1=5
package lc121_besttime_sell_stock {
  object Solution {
    def maxProfit(prices: Array[Int]): Int = {
      if (prices.isEmpty) return 0
      var maxProfit = Int.MinValue
      prices.reduceLeft((a,b)=>{
        maxProfit = max(maxProfit, b - a)
        min(a,b)
      })
      max(0,maxProfit)
    }
  }
}
