//
// Created by rui zhou on 2019-08-31.
//

/*
 * Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Note:

The input string length won't exceed 1000.
 */

#include <codech/codech_def.h>

using namespace std;

namespace {
    class Solution {
    public:
        int countSubstrings(string s) {
            int ans = 0;
            bool dp[1000][1000]= {false};
            for (size_t i=0;i<s.length();i++) {
                dp[i][i] = true;
                for (size_t j=0;j<i;j++) {
                    dp[j][i] = (i-j==1 && s[i]==s[j]) || (dp[j+1][i-1] == true && s[j]==s[i]);
                }
            }
            for (size_t i=0;i<s.length();i++) {
                for (size_t j=i;j<s.length();j++) {
                    if (dp[i][j]) {
                        ans++;
                    }
                }
            }
            return ans;
        }
    };
}