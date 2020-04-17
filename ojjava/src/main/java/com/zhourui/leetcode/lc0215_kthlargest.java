package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.PriorityQueue;

public class lc0215_kthlargest extends BaseSolution {
    class Solution {
        public int findKthLargest(int[] nums, int k) {
            PriorityQueue<Integer> pq=new PriorityQueue<>();
            for (int v:nums) {
                pq.offer(v);
                if (pq.size()>k) {
                    pq.remove();
                }
            }
            return pq.peek();
        }
    }
}
