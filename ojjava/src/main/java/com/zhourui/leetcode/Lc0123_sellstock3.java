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
    // 其实不需要多层循环，直接逆向一次，O(N)
    class Solution1 {
        public int maxProfit(int[] prices) {
            if (prices.length==0) return 0;
            int[] lr = new int[prices.length];
            int[] rl = new int[prices.length];

            int maxP = 0;
            int minP = prices[0];
            for (int i=1;i<prices.length;i++) {
                minP = min(prices[i],minP);
                lr[i] = max(prices[i] - minP, lr[i-1]);
            }

            maxP = prices[prices.length-1];
            for (int i=prices.length-2;i>=0;i--) {
                rl[i] = max(maxP - prices[i], rl[i+1]);
                maxP = max(prices[i],maxP);
            }

            maxP = lr[prices.length-1];
            for (int i=0;i<prices.length-1;i++) {
                maxP = max(maxP, lr[i]+rl[i+1]);
            }
            return maxP;
        }
    }

    @Override
    public boolean test() {
        var slu = new Solution();
        boolean ret = true;

        int[]arr1 = {3,3,5,0,0,3,1,4};
        ret &= slu.maxProfit(arr1) == 6;

        int[] arr ={1,2,3,4,5};
        ret &= slu.maxProfit(arr) == 4;
        return ret;
    }
}

