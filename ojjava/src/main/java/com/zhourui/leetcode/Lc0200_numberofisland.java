package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

// 这种matrix的，多半和BFS,DFS搜索有关
//可以使用DIR =[1,1,-1
public class Lc0200_numberofisland extends BaseSolution {
    class Solution {
        int[] DIR = new int[]{0, 1, 0, -1, 0};  // 4 direction
        public int numIslands(char[][] grid) {
            if (grid.length == 0) return 0;
            int m=grid.length,n = grid[0].length;

            boolean[][] visited = new boolean[m][n];
            int ans=0;
            for (int r=0;r<m;r++) {
                for (int c=0;c<n;c++) {
                    if (!visited[r][c]) {
                        ans += helper(m,n,grid,visited,r,c);
                    }
                }
            }
            return ans;
        }

        int helper(int m, int n, char[][]grid, boolean[][] visited, int r, int c) {
            if (r<0 || r>m || c<0 || c>n || grid[r][c]=='0' || visited[r][c]) {
                return 0;
            }
            visited[r][c] = true;
            for (int i=0;i<4;i++) {
                helper(m,n,grid,visited,r+DIR[i],c+DIR[i+1]);
            }
            return 1;
        }
    }
}
