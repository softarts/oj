//
// Created by rui.zhou on 2/28/2019.
//

/* amazon
 *Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 20m
 套路就是分析动规的子状态，与062不同的是，必须从右下角计算path
 */

#include <codech/codech_def.h>
using namespace std;

//从右下角开始
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        if (row==0) return 0;
        int col=grid[0].size();
        vector<vector<int>> dp = grid; //每一个都是到终点的pathsum
        int minPath=INT_MAX;
        for (int i=row-1;i>=0;i--) {
            for (int j=col-1;j>=0;j--) {
                if (j+1==col && i+1==row) {  //如果是最右下角，则为value
                    dp[i][j]= dp[i][j];
                } else if (j+1==col) { //最右侧的列
                    dp[i][j]= dp[i][j]+dp[i+1][j]; //自身+下一行
                } else if (i+1==row) { //最下面的一行
                    dp[i][j]= dp[i][j]+dp[i][j+1]; //自身+
                } else {
                    dp[i][j]=min(dp[i+1][j],dp[i][j+1])+dp[i][j];
                }
            }
        }
        return dp[0][0];  //最后返回起点的值
    }
};

DEFINE_CODE_TEST(064_minpathsum)
{
    Solution obj;
    {
        vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
        VERIFY_CASE(obj.minPathSum(grid),7);
    }

}
