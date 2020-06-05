/**
 * Created by rui.zhou on 04 Jun, 2020
 */
package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.HashMap;

public class Lc0219_containduplicate2 extends BaseSolution {
    class Solution {
        public boolean containsNearbyDuplicate(int[] nums, int k) {
            HashMap<Integer,Integer> hm = new HashMap();
            for (int i=0;i<nums.length;i++) {
                if (hm.containsKey(nums[i])) {
                    if (i-hm.get(nums[i]) <=k) {
                        return true;
                    } else {
                        hm.put(nums[i],i);
                    }
                } else {
                    hm.put(nums[i], i);
                }
            }
            return false;
        }
    }
}
