//
// Created by rui.zhou on 2/15/2019.
//

/*
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

 从前往后的匹配,主要是位置不好判断，需要考虑是否溢出。(非也，仍然可以实现)

 https://blog.csdn.net/hk2291976/article/details/51165010


 */

#include <codech/codech_def.h>
using namespace std;

class Solution0 {
public:
    string s0, p0;
    bool isMatch(string s, string p) {
        s0=s,p0=p;
        return myMatch(0,0);
    }
    bool myMatch(int si,int pj)
    {
        if(pj == p0.length()) {
            if(si == s0.length()) {
                return true;
            } else {
                return false;
            }
        }

        if(pj+1<p0.length()&& p0[pj+1] == '*')
        {
            if(si < s0.length() && (p0[pj] == '.' || p0[pj] == s0[si]))
                if(myMatch(si+1,pj))
                    return true;
            return myMatch(si,pj+2); // * as 0
        }
        if(p0[pj] == '.' || p0[pj] == s0[si])
            return myMatch(si+1,pj+1);
        return false;
    }
};


class Solution {
public:
    string s0, p0;
    static const int FRONT=-1;
    bool isMatch(string s, string p) {
        return myMatch(s,s.length()-1,p,p.length()-1);
    }
    bool myMatch(string s, int i, string p,int j)
    {
        if(j == FRONT) {
            if(i == FRONT) {
                return true;
            } else {
                return false;
            }
        }

        if(p[j] == '*')
        {
            if(i > FRONT && (p[j-1] == '.' || p[j-1] == s[i]))
                if(myMatch(s,i-1,p,j))
                    return true;
            return myMatch(s,i,p,j-2);
        }
        if(p[j] == '.' || p[j] == s[i])
            return myMatch(s,i-1,p,j-1);
        return false;
    }
};

DEFINE_CODE_TEST(010_regularmatch)
{
    Solution0 obj;
    {
        VERIFY_CASE(obj.isMatch("mississippi","mis*is*ip*."),true);
        VERIFY_CASE(obj.isMatch("mississippi","mis*is*p*."),false);
        VERIFY_CASE(obj.isMatch("aab","c*a*b"),true);
        VERIFY_CASE(obj.isMatch("ab",".*"),true);
        VERIFY_CASE(obj.isMatch("aa","a*"),true);
        VERIFY_CASE(obj.isMatch("","a*"),true);
        VERIFY_CASE(obj.isMatch("aaaaaaaaaaaaaaaa","a*aa*"),true);
        VERIFY_CASE(obj.isMatch("aaaaaaaaaaaaaaaa","a*ab*"),true);
        VERIFY_CASE(obj.isMatch("aaaaaaaaaaaaaaaa","a*a"),true);
    }
}