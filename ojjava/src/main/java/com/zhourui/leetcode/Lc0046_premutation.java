package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

// 全排列是个难题
// backtrace, 每一个元素都和剩余元素依次交换位置，
// 交换位置再进入下一个循环，和剩余的交换位置
// 退出这个循环之后，又要换回来
public class Lc0046_premutation extends BaseSolution {
    class Solution {
        public List<List<Integer>> permute(int[] nums) {
            List<List<Integer>> ans = new ArrayList<>();
            ArrayList<Integer> arr = new ArrayList<>();
            for (int i:nums) {
                arr.add(i);
            }
            helper(0,ans,arr);
            return ans;
        }


        void helper(int start, List<List<Integer>> ans, ArrayList<Integer> arr) {
            if (start==arr.size()) {
                ans.add((List<Integer>)arr.clone());
                /*for (int i:arr) {
                    System.out.printf(String.format("%d ",i));
                }
                System.out.println("\n");*/
                return;
            }

            for (int i=start;i<arr.size();i++) {
                Collections.swap(arr,start,i);
                helper(start+1,ans,arr);
                Collections.swap(arr,i,start);
            }
        }
    }

    @Override
    public boolean test() {
        new Solution().permute(new int[]{1,2,3});
        return true;
    }
}
