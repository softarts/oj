//
// Created by rui.zhou on 2/17/2019.
//

/*
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

 主要是对10的整除处理上，例如21120 false 0 为true,其他就是逆序整数

 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x==0) return true;
        if (x%10==0) return false;
        long ret=0;
        int y=x;
        while (x>0) {
            ret = ret*10+x%10;
            x=x/10;
            if (ret==x) {
                return true;
            }
        }
        return ret==y;
    }
};

/*
 *  if (x<0) return false;
        if (x<10) return true;
        if (x%10==0) return false;
        int remain = x;
        int rev = 0;
        while (remain > rev)
        {
            rev = rev*10 + remain%10;
            if (rev==remain)
                break;
            remain = remain/10;
        }
        return (remain==rev);
 */
DEFINE_CODE_TEST(009_palindromenumber)
{
    Solution obj;
    {
        VERIFY_CASE(obj.isPalindrome(121),true);

        for (int i=0;i<10;i++) {
            VERIFY_CASE(obj.isPalindrome(i),true);
        }
        VERIFY_CASE(obj.isPalindrome(10),false);
        VERIFY_CASE(obj.isPalindrome(1000),false);
        VERIFY_CASE(obj.isPalindrome(2),true);
        VERIFY_CASE(obj.isPalindrome(-121),false);
    }
}