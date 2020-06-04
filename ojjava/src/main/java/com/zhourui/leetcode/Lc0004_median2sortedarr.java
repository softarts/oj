package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

//[1,3],[2]->2
//[1,2],[3,4] -> (2+3)/2 = 2.5
// exp O(log(m+n))



public class Lc0004_median2sortedarr extends BaseSolution {
    class Solution {
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            int m = nums1.length;
            int n = nums2.length;
            if (m>n)
                return findMedianSortedArrays(nums2, nums1);

            int low = 0, high = m;
            double ret = 0;

            while (low <= high) {

            }
        }

    }
}
