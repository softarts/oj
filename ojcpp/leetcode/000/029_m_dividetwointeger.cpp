//
// Created by rui zhou on 05/04/18.
//

/*
 * https://leetcode.com/problems/divide-two-integers/description/
 * Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
 */


#include <codech/codech_def.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    // TLE 减法不行
    int divide0(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        int sign = ((dividend<0 && divisor <0) || (dividend>0 && divisor >0))?1:-1;
        dividend = abs(dividend); divisor = abs(divisor);
        int result = 0;
        while (dividend - divisor >= 0) {
            dividend -= divisor;
            result++;
        }

        return min(max(INT_MIN, result*sign), INT_MAX);
    }

    /*
     * int tot = 0;
        while (1) {
            int m = -1;int d2 = divisor;
            while (dividend - d2 >= 0) {
                d2 = d2<<1;
                m++;
            }
            tot += 1<<m;dividend -= d2;
            if (dividend <=0)
                break;
        }

        while (dividend - (d2<<1) > 0) {
            if (m<30) {
                d2 = d2<<1;
                m++;
            } else {
                break;
            }
        }
        tot += 1<<m;
        dividend = dividend - d2;
        while (dividend - divisor >= 0) {
            dividend -= divisor;
            tot++;
        }

     */

    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend<0 && divisor <0) || (dividend>0 && divisor >0))?1:-1;
        long long dvd = labs(dividend); long long dvs = labs(divisor);

        int tot = 0;
        while (dvd >= dvs) {
            long long  d2 = dvs;
            int m = 1;
            while (dvd >= (d2<<1) ) {
               d2 <<= 1;
               m <<=1;
            }
            tot += m;dvd-=d2;
        }
        return tot*sign;
    }
};


DEFINE_CODE_TEST(029_divide_two_integer)
{
    Solution obj;

    VERIFY_CASE(obj.divide(-2147483648,1),-2147483648);
    VERIFY_CASE(obj.divide(2147483647,1),2147483647);


    VERIFY_CASE(obj.divide(21,5),4);
    VERIFY_CASE(obj.divide(200,5),40);
    VERIFY_CASE(obj.divide(10,5),2);
    VERIFY_CASE(obj.divide(-2147483648,-1),2147483647);

}