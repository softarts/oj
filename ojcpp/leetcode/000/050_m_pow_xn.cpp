//
// Created by Rui Zhou on 1/3/18.
//
/*
https://leetcode.com/problems/powx-n/description/

Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

corner case,n=0
区分 n>0,n<0
 n%2=0,可以加速
退出条件 n==2
 n=3 ->转化为x*(pow(x),2)
*/

#include <codech/codech_def.h>
class Solution {
public:
    double myPow(double x, int n) {
        if (n==0)
            return 1;
        if (n==2)
            return x*x;
        if (n<0) {
            return 1/x * myPow(1/x, -(n+1));
        }
        if (n%2==0) { 
            return myPow(x*x, n/2);
        } else {
            return x*myPow(x*x, n/2);
        }
    }
};


DEFINE_CODE_TEST(050_pow_xn)
{
    Solution obj;
    cout<< INT_MAX << " " <<INT_MIN <<endl;
    VERIFY_CASE(obj.myPow(2.00000,10),1024);
    VERIFY_CASE(obj.myPow(2.10,3),9.261);
    //cout<< obj.myPow(34.00515,-3);
    //cout<< obj.myPow(0.44528,0);*/
    VERIFY_CASE(obj.myPow(1, -2147483648),1);
}
