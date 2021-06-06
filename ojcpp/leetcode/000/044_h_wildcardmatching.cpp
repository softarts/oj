//
// Created by rui zhou on 19/02/19.
//

/*
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false

 注意，本地没有010那种需要和前面的字母结合起来的关系
 a*   b*，完全可以分开 e.g. 匹配abbbbb
 */

#include <codech/codech_def.h>
using namespace std;

namespace wildcard {


//需要考虑 "" 和 "*"匹配这种情况
//good but TLE
    class Solution1 {
    public:
        string s0, p0;
        bool doMatch(int si, int pj) {
            if (si == s0.length() && pj == p0.length()) return true;
            if (si > s0.length() && pj < p0.length()) return false;
            if (pj < p0.length() && p0[pj] == '?') {
                return doMatch(si + 1, pj + 1);
            } else if (pj < p0.length() && p0[pj] == '*') {
                if (doMatch(si + 1, pj))   //a:*(n)
                    return true;
                else if (doMatch(si + 1, pj + 1))  // a : * (1)
                    return true;
                else return doMatch(si, pj + 1); // a:*(0)  "" "*"归类到这里
            } else if (si < s0.length() && pj < p0.length() && s0[si] == p0[pj]) {
                return doMatch(si + 1, pj + 1);
            }
            return false;
        }

        bool isMatch(string s, string p) {
            s0 = s;
            p0 = p;
            return doMatch(0, 0);
        }
    };

    // 精妙
    class Solution {
    public:
        bool isMatch(string s, string p) {
            int m=s.length(),n=p.length();
            vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
            dp[0][0]=true;  // empty string match empty string
            for (int i=0;i<n;i++) {
                if (p[i]=='*') {
                    dp[0][i+1] = dp[0][i]; //主要是处理连续*,另一层意思是当p 为*时,dp[0][pj]的match情况等于dp[0][pj-1]
                }
            }
            for (int i=1;i<=m;i++) {
                for (int j=1;j<=n;j++) {
                    if (p[j-1]=='*') {
                        dp[i][j]= dp[i][j-1] || dp[i-1][j];
                    } else {
                        dp[i][j]= dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='?');
                    }
                }
            }
            return dp[m][n];
        }
    };

    class Solution2 {
    public:

        bool isMatch(string s, string p)
        {
            return dfs(s, p, 0, 0) == 2;
        }
    private:
        int dfs(string& s, string& p, int si, int pi)
        {
            if (si == s.size() && pi == p.size()) return 2;    // matched
            if (si == s.size() && p[pi] != '*') return 0;      // unmatched: reached the end of s
            if (pi == p.size()) return 1;                       // unmatched: not reached the end of s
            if (p[pi] == '?' || s[si] == p[pi])
                return dfs(s, p, si+1, pi+1);
            if (p[pi] == '*') {                                 // calculate the shortest length p[pi] need to cover
                if (pi+1 < p.size() && p[pi+1] == '*')
                    return dfs(s, p, si, pi+1);                 // skip duplicate '*'
                for(int i = 0; i <= s.size()-si; ++i)
                {
                    int ret = dfs(s, p, si+i, pi+1);
                    if (ret == 0 || ret == 2)                   // reached the end of s, so return immediately
                        return ret;
                }
            }
            return 1;
        }
    };

    //https://blog.csdn.net/magicbean2/article/details/53990077  不明白DFS快速
//    class Solution0 {
//    public:
//        string s0, p0;
//
//        bool doMatch(int si, int pj) {
//            if (si == s0.length() && pj == p0.length()) return true;
//            if (si == s0.length() && p0[pj] != '*') return false;
//            if (pj==p0.length()) return false;
//
//            //if (si > s0.length() && pj < p0.length()) return false;
//
//            if (p0[pj] == '?' || s0[si] == p0[pj]) {
//                return doMatch(si + 1, pj + 1);
//            } else if (p0[pj] == '*') {
//                if (pj + 1 < p0.length() and p0[pj + 1] == '*')
//                    return doMatch(si, pj + 1);   //a:*(n)
//                return doMatch(si + 1, pj + 1);
//            }
//
//            return false;
//        }
//
//        bool isMatch(string s, string p) {
//            s0 = s;
//            p0 = p;
//            return doMatch(0, 0);
//        }
//    };


//    class Solution {
//    public:
//        string s0, p0;
//        static const int FRONT = -1;
//
//        bool doMatch(int si, int pj) {
//            if (pj == FRONT) {
//                if (si == FRONT)
//                    return true;
//                else
//                    return false;
//            }
//
//
//            if (p0[pj] == '?') {
//                return doMatch(si - 1, pj - 1);
//            } else if (p0[pj] == '*') {
//                if (doMatch(si - 1, pj))
//                    return true;
//                else if (doMatch(si - 1, pj - 1))
//                    return true;
//                else return doMatch(si, pj - 1);
//            } else if (s0[si] == p0[pj]) {
//                return doMatch(si - 1, pj - 1);
//            }
//            return false;
//        }
//
//        bool isMatch(string s, string p) {
//            s0 = s;
//            p0 = p;
//            return doMatch(s.length() - 1, p.length() - 1);
//        }
//    };
}


DEFINE_CODE_TEST(044_wildcard)
{
    wildcard::Solution obj;
    {
        VERIFY_CASE(obj.isMatch("","*"),true);  // 必须要考corner case
        VERIFY_CASE(obj.isMatch("aa","a"),false);
        VERIFY_CASE(obj.isMatch("aa","*"),true);
        VERIFY_CASE(obj.isMatch("cb","?a"),false);
        VERIFY_CASE(obj.isMatch("adceb","*a*b"),true);
        VERIFY_CASE(obj.isMatch("acdcb","a*c?b"),false);
        VERIFY_CASE(obj.isMatch("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba","*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*"),true);
    }
}

