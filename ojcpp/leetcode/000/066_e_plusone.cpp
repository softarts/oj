//
// Created by rui.zhou on 3/17/2019.
//

/*
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
 */
#include <codech/codech_def.h>
using namespace std;
//即模拟加法，需要考虑进位等情况
namespace {
    class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int h = 1;
            for (auto it = digits.rbegin(); it != digits.rend(); ++it)  {
                if (h != 0)  {
                    int r = (*it + h) % 10;
                    h = (*it + 1) / 10;
                    *it = r;
                }
            }
            if (h != 0)
                digits.insert(digits.begin(),h);
            return digits;
        }
    };
}
