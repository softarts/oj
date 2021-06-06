//
// Created by rui.zhou on 3/9/2019.
//

/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   实际上就是一个DP问题
   095也可以用DP来解决的
   即1..n的树 为i为root的树的个数
   如果数组为空，毫无疑问，只有一种BST，即空树，
Count[0] =1

如果数组仅有一个元素{1}，只有一种BST，单个节点
Count[1] = 1

如果数组有两个元素{1,2}， 那么有如下两种可能
1                       2
  \                    /
    2                1
Count[2] = Count[0] * Count[1]   (1为根的情况)
                  + Count[1] * Count[0]  (2为根的情况。

再看一遍三个元素的数组，可以发现BST的取值方式如下：
Count[3] = Count[0]*Count[2]  (1为根的情况)
               + Count[1]*Count[1]  (2为根的情况)
               + Count[2]*Count[0]  (3为根的情况)

所以，由此观察，可以得出Count的递推公式为
Count[i] = ∑ Count[0...k] * [ k+1....i]     0<=k<i-1
问题至此划归为一维动态规划。

 取决于左右子树的节点数,以1为root,左子树为0,右子树2个节点，所以dp[0]xdp[2]=2
 */

#include <codech/codech_def.h>
using namespace std;
namespace {
    class Solution {
    public:
        int numTrees(int n) {
            int dp[1000]={0};
            dp[0]=1;
            dp[1]=1;
            if (n<2)
                return dp[n];
            for (int i=2;i<=n;i++) {
                for (int j=0;j<i;j++) {
                    dp[i]+=dp[j]*dp[i-j-1];
                }
            }
            return dp[n];
        }
    };
}


DEFINE_CODE_TEST(096_uniquebst)
{
    Solution obj;
    {
        VERIFY_CASE(obj.numTrees(3),5);
    }
}
