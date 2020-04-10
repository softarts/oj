package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import static java.lang.Math.min;

//Input: s = 7, nums = [2,3,1,2,4,3]
//        Output: 2
//        Explanation: the subarray [4,3] has the minimal length under the problem constraint.
public class Lc0209_minsubarr extends BaseSolution {
    class Solution {
        public int minSubArrayLen(int s, int[] nums) {
            int cursum=0;
            int minlen = Integer.MAX_VALUE;

            for (int cur=0,end=0;end<nums.length;end++) {
                cursum+=nums[end];
                while (cur <=end && cursum>=s) {
                    minlen = min(end-cur+1,minlen);
                    cursum-=nums[cur];cur++;
                }
            }
            return minlen==Integer.MAX_VALUE?0:minlen;
        }
    }



}
