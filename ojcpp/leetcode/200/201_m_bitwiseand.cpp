//
// Created by rui zhou on 2020-02-10.
//

/*
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    // TLE
    class Solution0 {
    public:
        int rangeBitwiseAnd(int m, int n) {
            int ret=1;
            while (m<=n) {
                ret = ret&m;
                m++;
            }
            return ret;
        }
    };


    class Solution {
    public:
        int rangeBitwiseAnd(int m, int n) {
            n = min(~0 & m,n);
            while (m<=n) {
                ret = ret&m;
                m++;
            }
            return ret;
        }
    };
}