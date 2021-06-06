//
// Created by Rui Zhou on 13/4/18.
//

/*
 * https://leetcode.com/problems/valid-palindrome/description/
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.


 */


#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int start = 0, end = s.length()-1;
        while (start<=end) {
            int l = toupper(s[start]);
            if ((l>'Z' || l<'A') && (l<'0'|| l>'9')) {
                start++;
                continue;
            }
            int r =  toupper(s[end]);
            if ((r>'Z' || r<'A') && (r<'0'|| r>'9'))  {
                end--;
                continue;
            }
            if (l != r ) {
                return false;
            } else {
                start++;end--;
            }
        }
        return true;
    }
};

DEFINE_CODE_TEST(125_validpalindrome)
{
    Solution obj;
    {
        string s = "A man, a plan, a canal: Panama";
        VERIFY_CASE(obj.isPalindrome(s),true);
    }
    {
        string s = "race a car";
        VERIFY_CASE(obj.isPalindrome(s),false);
    }
    {
        string s = "0P";
        VERIFY_CASE(obj.isPalindrome(s),false);
    }
}