package com.zhourui.leetcode


// 思路 
package lc0200_numberofisland {
  object Solution {
    def numIslands(grid: Array[Array[Char]]): Int = {
      if(grid.isEmpty || grid(0).isEmpty){
        return 0
      }
      val m = grid.size
      val n = grid(0).size;

      //val dp:Array[Array[Int]];//vector<vector<int>> dp(m,std::vector<int>(n));
      //val dp = Array.ofDim[Int](m,n)
      val dp = Array.fill(m,n)(0)

      var count=0;
      for (i<-0 until m) {
        for (j<-0 until n) {
          if (dp(i)(j)==0) {
            if (bfs(grid,dp,(i,j)))
              count +=1;
          }
        }
      }
      count;
    }

    def bfs(grid:Array[Array[Char]], dp:Array[Array[Int]],pos:(Int,Int)):Boolean = {
      val m = grid.length
      val n = grid(0).length
      if (pos._1>=m || pos._2>=n || pos._1<0 || pos._2<0) {
        return false
      }
      if (dp(pos._1)(pos._2) == 1) {
        false
      } else if (dp(pos._1)(pos._2) == 0 && grid(pos._1)(pos._2) == '1') {
        dp(pos._1)(pos._2) = 1
        // right
        bfs(grid, dp, (pos._1, pos._2 + 1))
        // down
        bfs(grid, dp, (pos._1 + 1, pos._2))
        // up
        bfs(grid, dp, (pos._1 - 1, pos._2))
        // left
        bfs(grid, dp, (pos._1, pos._2 - 1))
        true;
      } else {
        false
      }
    }
  }
}
