package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Collections;
import java.util.PriorityQueue;


public class Lc1046_laststoneweight extends BaseSolution {
    class Solution {
        public int lastStoneWeight(int[] stones) {
            PriorityQueue<Integer> pq = new PriorityQueue(stones.length,Collections.reverseOrder());
            for (int stone : stones) {
                pq.add(stone);
            }
            while (true) {
                if (pq.isEmpty()) {
                    return 0;
                } else if (pq.size()==1) {
                    return pq.peek();
                } else {
                    var y = pq.peek();pq.remove();
                    var x = pq.peek();pq.remove();
                    if (x!=y) {
                        pq.offer(y-x);
                    }
                }
            }
        }
    }
    @Override
    public boolean test() {
        boolean ret = true;
        {
            int arr[] = {2,7,4,1,8,1}; //STATIC INITIALIZATION
            ret &= new Solution().lastStoneWeight(arr)==1;
        }
        return ret;
    }

    @Override
    public String name() {return "1046 last stone";}

}

