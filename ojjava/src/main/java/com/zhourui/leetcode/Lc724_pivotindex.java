package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;
import java.util.List;


//Input: nums = [1,7,3,6,5,6]
//        Output: 3
//0, 1, 8, 11,17,22
//27,20,17,11,6 ,0
public class Lc724_pivotindex extends BaseSolution {
    class Solution {
        public int pivotIndex(int[] nums) {
            if (nums.length==0) return -1;
            int[]left=new int[nums.length];left[0]=0;
            int[]right=new int[nums.length];right[nums.length-1]=0;
            for (int i=1;i<nums.length;i++) {
                left[i]=left[i-1]+nums[i-1];
            }
            for (int i=nums.length-2;i>=0;i--) {
                right[i]=right[i+1]+nums[i+1];
            }

            for (int i=0;i<nums.length;i++) {
                if (left[i]==right[i])
                    return i;
            }
            return -1;
        }
    }
}
