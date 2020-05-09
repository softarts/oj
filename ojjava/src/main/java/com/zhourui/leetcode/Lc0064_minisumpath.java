package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;
import static java.lang.Integer.*;

// 这种类似maze，对于board，就是用双重循环，DP来寻找最小值，比自己最初的代码写的更漂亮
//因为先计算了0row和0 col的值。最后再从1，1开始计算
public class Lc0064_minisumpath extends BaseSolution {
    class Solution {
        public int minPathSum(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
            for (int i=1;i<n;i++) {
                grid[0][i] = grid[0][i-1] + grid[0][i];
            }

            for (int i=1;i<m;i++) {
                grid[i][0] = grid[i-1][0] + grid[i][0];
            }

            for (int i=1;i<m;i++) {
                for (int j=1;j<n;j++) {
                    grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
                }
            }
            return grid[m-1][n-1];

        }
    }
}
