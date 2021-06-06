//
// Created by rui.zhou on 3/16/2019.
//

/*
 * Given an input string, reverse the string word by word.



Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 */

#include <codech/codech_def.h>
#include <numeric>
using namespace std;

namespace {
    class Solution {
    public:
        string reverseWords(string s) {
            stringstream ss(s);
            string tmp;
            vector<string> ret;
            while (getline(ss,tmp,' ')) {
                ret.emplace_back(tmp);
            }
            string s0;
            for (int i=ret.size()-1;i>=0;i--) {
                s0+=ret[i];
                if (i!=0)
                    s0+=" ";
            }
            return s0;
        }
    };

    class Solution1 {
    public:
        string reverseWords(string s) {
            stringstream ss(s);
            string tmp;
            string res;
            while (getline(ss,tmp,' ')) {
                if (!tmp.empty())
                    res = res.empty()?tmp:tmp+" "+res;
            }
            return res;
        }
    };
}
DEFINE_CODE_TEST(151_reverse_word)
{
    Solution obj;
    {
        VERIFY_CASE(obj.reverseWords("  hello world!  "),"world! hello");
        VERIFY_CASE(obj.reverseWords("the sky is blue"),"blue is sky the");
    }
}