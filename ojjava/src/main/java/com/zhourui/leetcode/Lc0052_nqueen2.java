package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import static java.lang.StrictMath.abs;

// 计算一共有多少种方案
// backtracing 方法，对于每一个摆放，都计算是否成立
// 使用一个List<Integer>来表示摆放位置.
public class Lc0052_nqueen2 extends BaseSolution {
    class Solution {
        private int ans=0;
        public int totalNQueens(int n) {
            ArrayList<Integer> place = new ArrayList<>();
            helper(0,n,place);
            return ans;
        }

        void helper(int start, int n, ArrayList<Integer> place) {
            if (start==n) {
                ans++;return;
            }
            //这里犯了一个错误，使用了多一层循环row=start->n
            for (int col=0;col<n;col++) {
                if (verify(col,place)) {
                    place.add(col);
                    helper(start+1,n,place);
                    place.remove(place.size()-1);
                }
            }
        }

        boolean verify(int col, ArrayList<Integer> place) {
            int row = place.size();
            for (int r=0;r<place.size();r++) {
                int c = place.get(r);
                int x=abs(c-col);
                int y=abs(r-row);
                if (x==0 || x==y) {
                    return false;
                }
            }
            return true;
        }

    }
}
