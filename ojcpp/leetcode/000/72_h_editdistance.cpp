/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
2021-05-08
可以insert, delete,replace
每次只能转换一个字符，需要转换多少次才能从word1 换到word2
horse -> ros , 3

intention -> execution，5
这种求极值的一般都是用DP
可以把问题分解成子问题:  
AB/BC 需要编辑多少次
使用dp[i][j]来表表示 所在位置的编辑长度,i指word1，j指word2的位置
1. if A[i] == B[j] dp[i][j] = dp[i-1][j-1]   
2. 不相等 dp[i][j] = min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1
初始化
需要对第一行第一列赋值，即把A完全转换到B的情况
*/

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int minDistance(string word1, string word2) {
            if (word1.empty() || word2.empty()) {
                return max(word1.length(),word2.length());
            }

            vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1,0));
            for (int i=0;i<=word1.length();i++) {
                dp[i][0]=i;
            }
            for (int i=0;i<=word2.length();i++) {
                dp[0][i]=i;
            }
            for (int i=1;i<=word1.length();i++) {
                for (int j=1;j<=word2.length();j++) {
                    dp[i][j] = (word1[i-1] == word2[j-1])?dp[i-1][j-1]:min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
                }
            }
            return dp[word1.length()][word2.length()];
        }
    };
}