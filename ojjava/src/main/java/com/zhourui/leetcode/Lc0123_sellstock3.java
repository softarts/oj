/**
 * Created by rui.zhou on 28 May, 2020
 */
package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import static java.lang.Integer.max;
import static java.lang.Integer.min;


//Input: [3,3,5,0,0,3,1,4]
//Output: 6
//Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// 最多2個transaction
// buy-sell才能buy
// 猜测使用dp,
public class Lc0123_sellstock3 extends BaseSolution {
    // 这个解法是O(N^2)
    class Solution {
        public int maxProfit(int[] prices) {
            int maxP = 0;
            for (int i=0;i<prices.length;i++) {
                int p0 = helper(prices,0,i);
                int p1 = helper(prices,i+1,prices.length-1);
                maxP = max(p0+p1,maxP);
            }
            return maxP;
        }

        int helper(int []arr, int start, int end) {
            int maxP = 0;
            int minP = Integer.MAX_VALUE;
            for (int i=start;i<=end;i++) {
                minP = min(arr[i],minP);
                maxP = max(arr[i]-minP,maxP);
            }
            return maxP;
        }
    }
    // 如果用DP呢？
    // 这个题和那个11xx很像，用n层循环
    

    @Override
    public boolean test() {
        var slu = new Solution();
        int arr[]={1,2,3,4,5};
        return slu.maxProfit(arr) == 4;
    }
}
