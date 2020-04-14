package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.HashMap;
import static java.lang.Math.max;

//[0,1,0,1,0,0,1,1]
//0 和 1 的个数相等 的最长子数组长度
//这道题和那个能整除的最长长度很相似，待补充

public class Lc0525_contiguousarray extends BaseSolution {
    class Solution {
        public int findMaxLength(int[] nums) {
            int sum = 0;
            var m = new HashMap<Integer,Integer>();
            m.put(0, -1);
            int maxLen = 0;
            for (int i=0;i<nums.length;i++) {
                sum+=nums[i]==0?-1:nums[i];
                if (m.containsKey(sum)) {
                    maxLen = max(maxLen, i-m.get(sum));
                } else {
                    m.put(sum, i);
                }
            }
            return maxLen;
        }
    }
}
