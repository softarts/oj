//
// Created by rui zhou on 2020-01-02.
//

/*
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
 9:22
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        string convertToTitle(int n) {
            string ans;
            char tbl[27];
            for (int i=1;i<27;i++) {
                tbl[i] = 'A'+i-1;
            }
            tbl[0]='Z';

            while (n>0) {
                ans+=tbl[n%26];
                n=(n-1)/26; //避免进位
            }
            reverse(ans.begin(),ans.end());
            return ans;

        }
    };



}

DEFINE_CODE_TEST(168_excelsheetconvert)
{
    Solution obj;
    {
        VERIFY_CASE(obj.convertToTitle(1),"A");
        VERIFY_CASE(obj.convertToTitle(26),"Z");
        VERIFY_CASE(obj.convertToTitle(27),"AA");
        VERIFY_CASE(obj.convertToTitle(701),"ZY");
        VERIFY_CASE(obj.convertToTitle(702),"ZZ");
    }

}