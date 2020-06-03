package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import static java.lang.Integer.max;

// [2,3,1,1,4] ->true
//Input: nums = [3,2,1,0,4]
//Output: false
// 每一个元素表示能走几步,判断能否到达终点
// 用end 表示当前能达到的最大范围,判断每个元素，update end的值
public class Lc0055_jumpgame extends BaseSolution {
    class Solution {
        public boolean canJump(int[] nums) {
            int end = 0;
            int cur = 0;
            while (cur < nums.length && cur<=end) {
                end = max(end,cur+nums[cur]);
                if (end>=nums.length-1)
                    return true;
                cur++;
            }
            return end>=nums.length-1?true:false;  //可能最后一步才到达终点
        }
    }
}
