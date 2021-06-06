//
// Created by rui.zhou on 12/2/2019.
//
// 4:12pm
/*
 * Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.



Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122
S doesn't contain \ or "
 */

#include <codech/codech_def.h>

using namespace std;

namespace {
    class Solution {
    public:
        string reverseOnlyLetters(string S) {
            int start = 0,end=S.length()-1;
            while (true) {
                while (start<S.length() && !isalpha(S[start])) start++;
                while (end>=0 && !isalpha(S[end]) ) end--;
                if (start<end) {
                    swap(S[start],S[end]);start++,end--;
                } else {
                    break;
                }
            }
            return S;
        }
    };
}

DEFINE_CODE_TEST(917_reverseletters)
{
    Solution obj;
    {
        VERIFY_CASE(obj.reverseOnlyLetters("ab-cd"),"dc-ba");
        VERIFY_CASE(obj.reverseOnlyLetters("a-bC-dEf-ghIj"),"j-Ih-gfE-dCba");
        VERIFY_CASE(obj.reverseOnlyLetters("Test1ng-Leet=code-Q!"),"Qedo1ct-eeLg=ntse-T!");
    }

}