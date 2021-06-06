//
// Created by rui.zhou on 3/9/2019.
//

/*
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
这个题必须倒过来看,6只能去4,1;5只能去1,8,所以倒过来就是4,1选出一个最小sum,那就是7;而1,8选出一个，那就是1+5=6,，这样自底向上
 最后选出dp[0]就是最短路径.一开始以为5可以去4,1,8,那是错的
Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */
#include <codech/codech_def.h>
using namespace std;

namespace lc120 {
    //从下往上, dp[0]=dp[0]和dp[1]得最小值+上一层triangle的值

    class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            if (triangle.empty())
                return 0;
            int sz=triangle.size();
            vector<int> dp{triangle[sz-1]};//取最后一行的值作为起始值
            for (int i=sz-2;i>=0;i--) { //layer层次
                for (int j=0;j<triangle[i].size();j++) {
                    dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
                }
            }
            return dp[0];
        }
    };
}

DEFINE_CODE_TEST(120_triangle)
{
    lc120::Solution obj;
    {
        vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
        VERIFY_CASE(obj.minimumTotal(triangle),11);
    }

}
