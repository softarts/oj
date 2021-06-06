//
// Created by rui.zhou on 2019/9/11.
//

/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int lengthOfLastWord(string s) {
            int ans = 0, prev = 0;
            for (int i=0;i<s.length();i++) {
                if (s[i]==' ') {
                    if (ans!=0)
                        prev = ans;
                    ans = 0;
                } else {
                    ans++;
                }
            }
            return ans==0?prev:ans;
        }
    };
}

DEFINE_CODE_TEST(058_last_words) {
    Solution obj;
    {
        VERIFY_CASE(obj.lengthOfLastWord("Hello World"), 5);
        VERIFY_CASE(obj.lengthOfLastWord("a "), 1);
        VERIFY_CASE(obj.lengthOfLastWord("b a  "), 1);
    }
}
