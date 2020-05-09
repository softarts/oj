package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

//Input: nums = [4,5,6,7,0,1,2], target = 0
//        Output: 4
//需要
public class Lc0033_searchinrotatedarr extends BaseSolution {
    class Solution {
        public int search(int[] nums, int target) {
            if (nums==null||nums.length==0) return -1;
            int lo=0,hi=nums.length-1;
            while (lo<=hi) {
                int mid=(lo+hi)/2;
                if (nums[mid]==target) return mid;
                if (nums[mid]>=nums[lo]) { //left is sorted，需要>=这个比较符，主要是mid和lo是同一个元素，导致去右侧寻找
                    if (target<nums[mid] && target>=nums[lo]) { // in left part
                        hi = mid-1;
                    } else { //right part
                        lo = mid+1;
                    }
                } else { // left is not sorted
                    if (target>nums[mid] && target<=nums[hi]) { // move to right
                        lo = mid+1;
                    } else {
                        hi = mid-1;
                    }
                }
            }
            return -1;
        }
    }

    @Override
    public boolean test() {
        boolean ret=true;
        ret &=new Solution().search(new int[]{3,1},1)==1;

        /*ret &=new Solution().search(new int[]{1},2)==-1;
        ret &=new Solution().search(new int[]{1,3},4)==-1;
        ret &=new Solution().search(new int[]{},5)==-1;
        ret &=new Solution().search(new int[]{4,5,6,7,0,1,2},3)==-1;*/
        return ret;
    }
}


/*
public int search(int[] A, int target) {
        if (A == null || A.length == 0) {
            return -1;
        }

        int l = 0;
        int r = A.length - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (A[mid] == target) {
                return mid;
            }

            // left side is sorted.
            // BUG 1: if don't use >= , and use L < r in while loop, than there is some problem.
            if (A[mid] >= A[l]) {
                if (target > A[mid] || target < A[l]) {
                    // move to right;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (target < A[mid] || target > A[r]) {
                    // move to left;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }

    class Solution {
public:
     int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            int mid = (hi+lo)/2;
            if (nums[lo] < nums[mid]) {
                if (target < nums[mid]) {
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            } else { //pivotal  7 8 9 0 1 2 3 4 ...target = 8
                if (target > nums[mid]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return lo==hi && nums[lo]==target?lo:-1;
    }
};
 */