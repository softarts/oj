//
// Created by rui.zhou on 2/21/2019.
//

/*
 * Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

KMP 解法？
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;


// KMP 解法
//https://blog.csdn.net/yutianzuijin/article/details/11954939/
//算法导论32.4
//阮一峰 http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
//ABCDABD ->最大公共长度，必须从前到后连续排列
//首先，要了解两个概念："前缀"和"后缀"。
//"前缀"指除了最后一个字符以外，一个字符串的全部头部组合；
//"后缀"指除了第一个字符以外，一个字符串的全部尾部组合。
//目的是找出公共的头部和尾部组合,例如ABCDABD，D处为0
//ABCDAB, B处为2，因为AB为公共组合。
//构建next table,找出pattern 每一个字符处对应的公共长度，
//如果是ABCDABA，最后一个A的值怎么设置?0

// ABCDAB -> AB[2]
// kmp search

//my kmp
class Solution {
public:
    int strStr(string haystack, string needle) {
        const int nl = needle.length();
        if (nl == 0) return 0;

        vector<int> next(nl, 0);
        int i=0,j=-1;
        //跳表，状态机的概念
        //1. next[0]=0, 第一个和最后一个必定是0,所以用最后一个位置来保存前一个next 值
        //2.对于每个needle[i],取出next[i-1]处的idx(此处使j=i-1),如果相等，累加idx
        //如果第2步不相等，需要回退到上一层,取idx=next[idx]
        while (i<nl-1) {
            if (j==-1 || needle[j]==needle[i]) {
                next[++i]=++j;  //第一个和最后一个必定是0,所以用最后一个位置来保存前一个next 值:因此先++i, next[++i]
            } else {
                j=next[j];i++;
            }
        }

        int hl = haystack.length();
        for (int i = 0, j = 0; i < hl; i++){
            if (j < nl && haystack[i] == needle[j]) {
                j++;
            } else {
                while (j > 0){
                    j = next[j];
                    if (haystack[i] == needle[j]){
                        j++;
                        break;
                    }
                }
            }
            if (j == nl) return i - nl + 1;
        }
        return -1;
    }
};


// KMP
class Solution1 {
public:
    int strStr(string haystack, string needle) {
        int m = needle.length();
        if (m == 0) return 0;
        // build next table, size=m+1
        vector<int> next(m+1, 0);
        for (int i = 0; i < m; i++){
            int j = i;
            while (j > 0) {
                //取出上一个next[]的值，如果为1，表示有匹配到一个字符
                //需要继续比较下一个字符,取next[]的值为needle的新idx来比较
                j = next[j];
                if (needle[i] == needle[j]){
                    next[i+1] = j + 1; // 等于前一个J值+1,即递增
                    break;
                }
                //退出条件
                // next table的一个作用是，value为需要比较的idx位置，0表示要从0处起比较

            }
        }

        int n = haystack.length();
        for (int i = 0, j = 0; i < n; i++){
            if (j < m && haystack[i] == needle[j]) j++;
            else while (j > 0){
                    j = next[j];
                    if (haystack[i] == needle[j]){
                        j++;
                        break;
                    }
                }
            if (j == m) return i - m + 1;
        }
        return -1;
    }
};

// brute force
class Solution0 {
public:
    // too ugly and with problem!
    //一旦找到第一个char一样，就去比较下一个char,但这个时候必须记住第一个char的haystack的位置不能移动！
    int strStr(string haystack, string needle) {
        int lenh = haystack.length();
        int lenn = needle.length();
        if (lenn==0) return 0;
        if (lenn>lenh) return -1;

        auto cmp = [&](int i){
            int idx = 0;
            while (idx<lenn && haystack[i]==needle[idx]) {
                i++;idx++;
            }
            if (idx==lenn)
                return true;
            else
                return false;
        };

        for (int i =0;i<lenh-lenn+1;i++) {
            if (cmp(i))
                return i;
        }
        return -1;
    }
};

DEFINE_CODE_TEST(028_strstr)
{
    Solution1 obj;
    {
        VERIFY_CASE(obj.strStr("aabaaabaaac","aabaaac"),4);

        VERIFY_CASE(obj.strStr("BBC ABCDAB ABCDABCDABDE","ABCDABD"),0);
        VERIFY_CASE(obj.strStr("ABABDABACDABABCABAB","ABABCABAB"),0);
        VERIFY_CASE(obj.strStr("abc","a"),0);
        VERIFY_CASE(obj.strStr("",""),0);
        VERIFY_CASE(obj.strStr("abc",""),0);
        VERIFY_CASE(obj.strStr("abc","b"),1);
        VERIFY_CASE(obj.strStr("abc","d"),-1);
        VERIFY_CASE(obj.strStr("abc","abcde"),-1);
        VERIFY_CASE(obj.strStr("abc","abc"),0);
        VERIFY_CASE(obj.strStr("aaaaa","bba"),-1);
        VERIFY_CASE(obj.strStr("hello","ll"),2);
        VERIFY_CASE(obj.strStr("mississippi","issip"),4);

    }
}