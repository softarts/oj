/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
2021-05-08

dp[i][j] 为当前位置的最长公共子串
*/

#include <codech/codech_def.h>
using namespace std;
namespace {
    class Solution {
    public:
        int minDistance(string word1, string word2) {
            vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,0));
            for (int i=1;i<=word1.length();i++) {
                for (int j=1;j<=word2.length();j++) {
                    dp[i][j]=(word1[i-1]==word2[j-1]?dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]));
                }
            }
            return word1.length()+word2.length()-dp[word1.length()][word2.length()]*2;
        }
    };
}

DEFINE_CODE_TEST(583_deletetwostring)
{
    Solution obj;
    VERIFY_CASE(obj.minDistance("a","b"),2);
    VERIFY_CASE(obj.minDistance("a","a"),0);
}
