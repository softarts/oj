/**
 * Created by rui.zhou on 19 May, 2020
 */
package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;

import static java.lang.Integer.max;

//Input: [10,9,2,5,3,7,101,18]
//Output: 4
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// unsort的数组，找出最长上升序列,看上去是个DP
//9:51
//想不出来,一直在想如何从已有的dp序列得到新的数据，现在明白了，不应该从后面
//应该从之前的数值入手，比它小的都可以算上升序列
// 直接用dp[i]来表示0..i之间的长度
public class Lc0300_longestincseq extends BaseSolution {
    class Solution {
        public int lengthOfLIS(int[] nums) {
            int dp[] = new int[nums.length];
            Arrays.fill(dp,1); // 必须设置为,因为在这个数组里，默认序列长度就是1
            int maxl=0;
            for (int i=0;i<nums.length; i++) {
                for (int j=0;j<i;j++) {
                    if (nums[j]<nums[i]) {
                        dp[i] = max(dp[j]+1,dp[i]);
                    }
                }
                maxl = max(maxl, dp[i]);
            }
            return maxl;

        }
    }

}
