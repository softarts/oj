//
// Created by rui.zhou on 2/23/2019.
//

/*
 *
 */

/*
 * The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.
思路
 一个递进的过程，看上去很复杂，其实就是
 就是对string进行count,先取第一个字符，然后计算有多少个连续相同的，记下来转化
 成string,接着检查下一个.
 */
#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp{"1"};
        for (int i=1;i<=n;i++) {
            string phrase=dp[i-1];
            string newPhrase="";
            char currentChar = phrase[0];
            int count = 0;
            for (auto ch:phrase) {
                if (ch==currentChar) {
                    count++;
                } else {
                    newPhrase+=to_string(count)+currentChar;
                    currentChar=ch;
                    count=1;
                }
            }
            newPhrase+=to_string(count)+currentChar;
            dp.emplace_back(newPhrase);
        }
        return dp[n-1];
    }
};

DEFINE_CODE_TEST(038_countsay)
{
    Solution obj;
    {
        VERIFY_CASE(obj.countAndSay(1),"1");
        VERIFY_CASE(obj.countAndSay(2),"11");
        VERIFY_CASE(obj.countAndSay(4),"1211");
    }
}