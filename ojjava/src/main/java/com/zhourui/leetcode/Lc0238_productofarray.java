package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

// 从左往右遍历，每个元素都存入左侧所有数组的乘积,跳开第一个
// 从右往左遍历，每个元素都存入右侧所有数组的乘积,跳开最后一个

public class Lc0238_productofarray extends BaseSolution {
    class Solution {
        public int[] productExceptSelf(int[] nums) {
            int[] ans = new int[nums.length];
            ans[0]=1;ans[nums.length-1]=1;
            int product = 1;
            for (int i=1;i<nums.length;i++) {
                product *= nums[i-1];
                ans[i]=product;
            }
            product=1;
            for (int i=nums.length-2;i>=0;i--) {
                product *= nums[i+1];
                ans[i]=ans[i]*product;
            }
            return ans;
        }
    }
}
