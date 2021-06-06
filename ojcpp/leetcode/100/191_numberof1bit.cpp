//
// Created by Rui Zhou on 5/4/18.
//

/*
 * https://leetcode.com/problems/number-of-1-bits/description/
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

 */

#include <codech/codech_def.h>


class Solution {
public:
    int hammingWeight(uint32_t n) {
        //1011 & 1010 -> 1010  +1
        //1010 & 1001  +1
        //1000 & 0111 -> 0
        //1000 & 0111  ==0
        int count =0;
        while (n) {
            count++;
            n = n & n-1;
        }
        return count;
    }
};

DEFINE_CODE_TEST(191_numberof1bits)
{
    Solution obj;
    {
        VERIFY_CASE(obj.hammingWeight(11),3);
    }
}