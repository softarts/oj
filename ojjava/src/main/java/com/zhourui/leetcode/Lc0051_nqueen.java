package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import static java.lang.StrictMath.abs;

//皇后问题
// 非常漂亮的实现, 使用backtracking,
// 一个关键是使用linkedlist来保存当前已排好的nqueen,然后在新添加的一行，检查每个col，是否不违反当前规则。
// 如果能达到最后一行，表示已有一个solution
public class Lc0051_nqueen extends BaseSolution {
    class Solution {
        public List<List<String>> solveNQueens(int n) {
            List<List<String>> result = new ArrayList();
            LinkedList<Integer> place = new LinkedList();
            helper(0,n,result,place);
            return result;
        }

        public String getString(int n, int col){
            String str = "";
            for(int j=0;j<n;j++){
                str += (j==col) ? "Q" : ".";
            }
            return str;
        }

        void helper(int row, int n, List<List<String>> result, LinkedList<Integer> place) {
            if (row==n) { // no more row
                ArrayList<String> list = new ArrayList<>();
                for(int col : place){
                    list.add(getString(n, col));
                }
                result.add(list);
                return;
            }

            for (int col=0;col<n;col++) {
                if (valid(col, place)) {
                    place.add(col);
                    helper(row+1,n,result,place);
                    place.removeLast();
                }
            }
        }
        // check the lastest row.
        boolean valid(int col,List<Integer> place) {
            var row = place.size();
            for (int r0=0;r0<place.size();r0++) {
                var c0 = place.get(r0);// where Q row
                var xdist = abs(c0-col);
                var ydist = abs(row-r0); // 垂直2条边相等，维持在45度斜线上
                if (xdist==ydist || xdist==0) return false;
            }
            return true;
        }


    }
}

/*
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> used(2*n, 0);
        vector<vector<int>> used3(3, used);
        return dfs(used3, 0, n);
    }
    int dfs(vector<vector<int>>& used3, int row, int limit){
        if(row == limit){
            return 1;
        }
        int rnt = 0;
        for(int i=0; i<limit; i++){
            int lid = i - row + limit - 1;
            int rid = i + row;
            if(!used3[0][i] && !used3[1][lid] && !used3[2][rid]){
                used3[0][i] = true, used3[1][lid] = true, used3[2][rid] = true;
                rnt += dfs(used3, row+1, limit);
                used3[0][i] = false, used3[1][lid] = false, used3[2][rid] = false;
            }
        }
        return rnt;
    }
};
 */