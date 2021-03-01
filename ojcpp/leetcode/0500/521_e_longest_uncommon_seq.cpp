//
// Created by rui.zhou on 3/17/2019.
//

/*
 * Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc"
Output: 3
Explanation: The longest uncommon subsequence is "aba" (or "cdc"),
because "aba" is a subsequence of "aba",
but not a subsequence of any other strings in the group of two strings.
Note:

Both strings' lengths will not exceed 100.
Only letters from a ~ z will appear in input strings.
 此题的最sb之处
 aaaaaa 和 aaa， longest uncommon 是aaaaaa,因为他不可以在b中通过删除某字符得到
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int findLUSlength(string a, string b) {
            return a==b?-1:(max(a.length(),b.length()));
        }
    };

    class Solution1 {
    public:
        int findLUSlength(string a, string b) {
            int i = 0; int j = 0;
            while (i < a.size() && j < b.size()){
                if (a[i] == b[j])
                    i++;
                j++;
            }
            return (i == a.size());

        }
    };
}

DEFINE_CODE_TEST(521_longest_uncommonseq)
{
    Solution1 obj;
    {
        VERIFY_CASE(obj.findLUSlength("aa","aaa"),3);
    }

}