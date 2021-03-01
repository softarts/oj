package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.List;

public class Lc0039_combinationsum extends BaseSolution {
    class Solution {
        public List<List<Integer>> combinationSum(int[] candidates, int target) {

        }

        private void dfs(List<List<Integer>> ret,List<Integer> comb,int start,int[] cand, int target) {
            if (target==0) {
                ret.add(comb);
                return;
            }
            for (int i=start; i< cand.length;i++) {
                
            }
        }
    }
}
