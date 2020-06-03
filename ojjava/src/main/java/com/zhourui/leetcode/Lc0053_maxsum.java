/**
 * Created by rui.zhou on 28 May, 2020
 */
package com.zhourui.leetcode;
import static java.lang.Integer.*;
import com.zhourui.codech.BaseSolution;

// 本題關鍵是要處理 全部是負數這種可能，所以每一個cursum 都必須做一個選擇
// 到底是加上前一個數還是用自己
public class Lc0053_maxsum extends BaseSolution {
    class Solution {
        public int maxSubArray(int[] nums) {
            int maxsum = Integer.MIN_VALUE;
            int cursum = 0;//nums[0];
            for (int i=0;i<nums.length;i++) {
                cursum = max(cursum+nums[i],nums[i]);
                maxsum = max(maxsum,nums[i]);
            }
            return maxsum;
        }
    }

}
