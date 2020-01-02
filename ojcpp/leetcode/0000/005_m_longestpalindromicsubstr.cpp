//
// Created by rui.zhou on 2/15/2019.
//
/*
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

找出字符串里最长的回文字符串
 
1.使用DP,用一个table来表示当前的状态,dp[i][j]=true表示start=i,end=j的字串为回文
2.遍历s,对于每个字符，再从0,i进行遍历dp,如果某字符串是回文，那么去掉头尾他仍然是回文,如果头尾相等也是回文
3.比较浪费的是每次都要从头开始比较，因为不知道前一个字符能形成的回文起始点在哪里。

backtracking通常需要上下context关系，需要剪枝，递归，这个题目里不是特别明显，从左到右/前后的字符没有特别明显的递归关系，用loop也可以
 参考131,使用loop来解决
 */
#include <codech/codech_def.h>
using namespace std;
namespace {
    // DP 要找到一个递推的空间，比如第一层循环i=0~n,第二层等于j=0~i
    class Solution {
    public:
        string longestPalindrome(string s) {
            bool dp[1000][1000]= {false};
            int start = 0;
            int maxlen = 1;
            for (int i=0;i<s.length();i++) {
                dp[i][i]=true;  //i 到 i，即字符本身是回文
                for (int j=0;j<i;j++) {
                    // j-i是否为回文,两个条件
                    // 1. 如果j+1 ~ i-1是回文并且s[j]==s[i],当i=0，循环没进来
                    // 2. 相邻字符相等(因为j+1和i-1无法覆盖相邻字符case)
                    dp[j][i] = (s[j]==s[i] && i-j==1) || (s[j]==s[i] && dp[j+1][i-1]==true );
                    if (dp[j][i] && maxlen<(i-j+1)) {
                        maxlen = i-j+1;
                        start=j;
                    }
                }
            }
            return s.substr(start,maxlen);
        }
    };
    //TLE
    class Solution1 {
    public:
        string longestPalindrome(string s) {
            int maxlen=1;
            int start=0,end=0;
            for (int i=0;i<s.length()-1;i++) {
                int len1 = search(s,i,i);
                int len2 = search(s,i,i+1);
                int len =max(len1,len2);
                if (len>maxlen) {
                    maxlen=len;
                    start=i-(len-1)/2;
                    end=i+len/2;
                }
            }
            return s.substr(start,maxlen);
        }
        int search(string &s, int left,int right) {
            while (left>=0 &&right<s.length() && s[left]==s[right]) {
                left--;right++;
            }
            return (right-left-1);
        }
    };
}

DEFINE_CODE_TEST(005_longestpalindrome) {
    Solution1 obj;
    {
        string s = "babad";
        VERIFY_CASE(obj.longestPalindrome(s),"bab");
    }
    {
        string s = "cbbd";
        VERIFY_CASE(obj.longestPalindrome(s),"bb");
    }
}
