//
// Created by rui.zhou on 1/28/2019.
//

/*
 * Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n>0) {
            count+=n/5;
            n/=5;
        }
        return count;
    }
};

DEFINE_CODE_TEST(172_factorial_trailing)
{
    Solution obj;
    {
        VERIFY_CASE(obj.trailingZeroes(3),0);
    }
    {
        VERIFY_CASE(obj.trailingZeroes(5),1);
    }
    {
        VERIFY_CASE(obj.trailingZeroes(6),1);
    }
}