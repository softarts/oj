package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import static java.lang.Integer.*;

//Input: cost = [10, 15, 20]
//        Output: 15
//        Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
//思路，可以走一步，也可以走两步，使用一个dp来保存
public class Lc0746_climbcost extends BaseSolution {
    class Solution {
        public int minCostClimbingStairs(int[] cost) {
            int[] dp = new int[1001];
            for (int i=2;i<=cost.length;i++) {
                dp[i]=min(cost[i-2]+dp[i-2],cost[i-1]+dp[i-1]);
            }
            return dp[cost.length];
        }
    }

    @Override
    public boolean test() {
        int[] arr = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        return (new Solution().minCostClimbingStairs(arr)==6);
    }

    @Override
    public String name() {
        return this.getClass().getSimpleName();
    }
}
