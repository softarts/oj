package com.zhourui.leetcode

// 归纳为
// 如果今天价格比昨天高，那么昨天买入，今天卖出(假如昨天已经卖出，那么取消，改为今天卖出)
// 如果今天比昨天价格低，那么就今天买入(取消昨天的买入)

package lc0122_buynsellstock2 {
  object Solution {
    def maxProfit(prices: Array[Int]): Int = {
      if (prices.isEmpty) return 0
      else (0 until prices.length-1).foldLeft(0)(
        (profit,i) =>{
          if (prices(i)<prices(i+1)) profit+prices(i+1)-prices(i) else profit
        }
      )
    }
  }
}
