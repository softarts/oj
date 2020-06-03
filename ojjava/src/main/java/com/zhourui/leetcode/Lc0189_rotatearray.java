/**
 * Created by rui.zhou on 03 Jun, 2020
 */
package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;
import java.util.Collections;
import java.util.stream.IntStream;

// 这个题巧秒的解法就是先全部reverse,再局部reverse
// java 里面居然没有
// stream 这个是 产生新的数组
// int[] arr = IntStream.rangeClosed(1,nums.length)
//                    .map(idx -> nums[nums.length-idx])
//                    .toArray();
public class Lc0189_rotatearray extends BaseSolution {
    class Solution {
        public void rotate(int[] nums, int k) {
            k = k%nums.length;
            reverse(nums,0,nums.length-1);
            reverse(nums,0,k-1);
            reverse(nums,k,nums.length-1);
        }

        void reverse(int[] arr, int start, int end) {
            while (start < end) {
                int tmp = arr[start];
                arr[start] = arr[end];
                arr[end] = tmp;
                start++;end--;
            }
        }
    }

    @Override
    public boolean test() {
        var slu = new Solution();
        int arr[]={-1};
        slu.rotate(arr,2);
        return arr[0]==-1;
    }
}
