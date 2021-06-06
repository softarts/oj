//
// Created by rui.zhou on 2/15/2019.
//

/*
 * Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long ret=0;
        while (x!=0) {
            ret = ret*10+x%10;
            x=x/10;
        }
        if (ret>INT_MAX || ret <INT_MIN)
            return 0;
        else
            return ret;
    }
};

DEFINE_CODE_TEST(007_reverseint)
{
    Solution obj;
    {
        VERIFY_CASE(obj.reverse(-123),-321);
        VERIFY_CASE(obj.reverse(123),321);
    }
}
