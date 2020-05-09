package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

// 就是套路，backtrace？
// 然而这里需要 在返回后把comb最后一个元素去掉，因为已被用过。
public class Lc0216_combinesum3 extends BaseSolution {
    class Solution {
        public List<List<Integer>> combinationSum3(int k, int n) {
            List<List<Integer>> ans=new ArrayList<>();
            LinkedList<Integer> comb=new LinkedList<>();
            helper(1,ans,comb,n,k);
            return ans;
        }

        void helper(int start, List<List<Integer>> ans, LinkedList<Integer> comb, int target, int k) {
            if (target == 0 && k==comb.size()) {
                ans.add((LinkedList) comb.clone());
                return;
            }
            if (comb.size() >= k) return;

            for (int i = start; i <= 9 && i<=target; i++) {
                comb.add(i);
                helper(i + 1, ans, comb, target - i, k);
                comb.removeLast();
            }
        }
    }

    @Override
    public boolean test() {
        return new Solution().combinationSum3(3,7).equals(new ArrayList<>(Arrays.asList(1,2,4)));
    }
}
