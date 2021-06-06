//
// Created by Rui Zhou on 9/3/18.
//

/*
 * https://leetcode.com/problems/sqrtx/description/
 * Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.


Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.

 12:24 -
 binary search problem. the mid point is not equal to sqrt, but it is the best choice...
class Solution {
public:
    int sqrt(int x) {
        if (0 == x) return 0;
        int left = 1, right = x, ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

 the pattern of binary search
 */

#include <codech/codech_def.h>

class Solution {
public:
    int mySqrt0(int x) {
        if (x==0)
            return 0;

        int i = binSearch(1, x/2, x);
        if (i*i > x) {
            return i-1;
        }
        return i;

    }

    int binSearch(int start, int end, int x) {
        if (start >= end) {
            return start;
        }
        int mid = ( end - start)/2 + start;
        if (mid*mid==x) {
            return mid;
        } else  if (mid*mid > x) {
            return binSearch(start, mid-1, x);
        } else {
            return binSearch(mid+1, end, x);
        }
    }

    //
    int mySqrt(int x) {
        if (x==0)
            return 0;
        int start = 1, end = x, answer;
        while (start<=end) {
            int mid = ( end - start)/2 + start;
            if (mid <= x/mid) {
                answer = mid;
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return answer;

    }
};

DEFINE_CODE_TEST(sqrtx)
{
    Solution obj;
//    RUN_CASE(obj.mySqrt(0), 0);
//    RUN_CASE(obj.mySqrt(4), 2);
//    RUN_CASE(obj.mySqrt(5), 2);
//    RUN_CASE(obj.mySqrt(8), 2);
//    RUN_CASE(obj.mySqrt(9), 3);
//    RUN_CASE(obj.mySqrt(100), 10);
/*
    RUN_CASE(obj.mySqrt(0), 0);
    RUN_CASE(obj.mySqrt(1), 1);
    RUN_CASE(obj.mySqrt(4), 2);
    RUN_CASE(obj.mySqrt(5), 2);
    RUN_CASE(obj.mySqrt(8), 2);
    RUN_CASE(obj.mySqrt(9), 3);
    RUN_CASE(obj.mySqrt(100), 10);
    */
    VERIFY_CASE(obj.mySqrt(2147395599), 46339);


}