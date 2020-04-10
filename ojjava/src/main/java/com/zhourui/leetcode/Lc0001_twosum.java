package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;

public class Lc0001_twosum extends BaseSolution {
    class Solution {
        public int[] twoSum(int[] nums, int target) {
            java.util.Arrays.sort(nums);
            int start=0,end=0;
            while (nums[start] + nums[end] != target) {
                if ((nums[start] + nums[end]) > target) {
                    end--;
                } else {
                    start++;
                }
            }
            int[] temp = new int[2];
            temp[0]=start;
            temp[1]=end;
            return temp;
        }
    }


    @Override
    public String name() {return "two sum";}

    @Override
    public boolean test() {
        int[] nums=new int[]{2,7,11,15};
        int[] result = new Solution().twoSum(nums, 9);
        //return (result == new int[]{0,1}) ;
        Arrays.sort(result);
        return Arrays.equals(result,new int[]{0,1});
        //return new int[]{0,1}.equals(result);
    }
}




