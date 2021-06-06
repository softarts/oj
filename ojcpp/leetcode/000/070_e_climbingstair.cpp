//
// Created by Rui Zhou on 3/4/18.
//

/*
 * https://leetcode.com/problems/climbing-stairs/description/
 * You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.


Example 1:

Input: 2
Output:  2
Explanation:  There are two ways to climb to the top.

1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output:  3
Explanation:  There are three ways to climb to the top.

1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
青蛙可以跳1格，也可以跳2格
 就是组合问题，
 */

#include <codech/codech_def.h>


class Solution {
public:
    int climbStairs(int n)
    {
        int f1 = 1;  // 只有1个台阶
        int f2 = 2;  //有2个台阶
        int fn = 0;
        if (n == 1) return f1;
        if (n == 2) return f2;
        if (n <= 0) return 0;
        for (int i=3;i<=n;i++)
        {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};


DEFINE_CODE_TEST(070_climbing_stairs)
{
    Solution obj;
    VERIFY_CASE(obj.climbStairs(3),3);
}