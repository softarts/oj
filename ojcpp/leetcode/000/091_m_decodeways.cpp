//
// Created by Rui Zhou on 29/3/18.
//

/*
 * https://leetcode.com/problems/decode-ways/description/
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
 111->1,1,1  / 1,11/ 11,1
 1111->1,1,1,1 / 1,11,1 / 11,11/ 11,1,1 /1,1,11
 11111->1,1,1,1,1/ 1,1,11,1

 class Solution:
    # @param s, a string
    # @return an integer
    def numDecodings(self, s):
        #dp[i] = dp[i-1] if s[i] != "0"
        #       +dp[i-2] if "09" < s[i-1:i+1] < "27"
        if s == "": return 0
        dp = [0 for x in range(len(s)+1)]
        dp[0] = 1
        for i in range(1, len(s)+1):
            if s[i-1] != "0":
                dp[i] += dp[i-1]
            if i != 1 and s[i-2:i] < "27" and s[i-2:i] > "09":  #"01"ways = 0
                dp[i] += dp[i-2]
        return dp[len(s)]

找出有多少种decode的方法，dfs恐怕TLE
2: DP
假设dp[i]为以i为结尾的字符串解码方式数量的总和。
假设当前index为i，当s[i]有效的时候，则dp[i] += dp[i - 1]。当s[i - 1]s[i]组成的字符串有效时(即和前一个数)，dp[i] += dp[i - 2]。
实际上我们并不需要一个额外的数组来储存，只需要两个变量来储存dp[i - 1]和dp[i - 2]即可。
Tips:
Time Complexity：
1、O(2^n)，DFS更适合求全部解码的结果，而不是计算有多少种解码的方法。
2、O(n)

 */

#include <codech/codech_def.h>
#include <string>
using namespace std;

namespace {
    // DFS
    class Solution {
    public:
        int numDecodings(string s) {
            int ret = decode(s, 0);
            return ret;
        }
        // TLE
        int decode(string s, int pos) {
            if (s.empty())
                return 0;
            if (s[0] == '0')
                return 0;
            if (s.size() == 1) {
                return 1;
            }
            if (s.size() == 2) {
                int c = 0;
                if (s[1] != '0') {
                    // 27,28,29,31,
                    c++;
                }
                int n = stoi(s);
                if (n < 27 && n >= 10) {
                    // 11...25,26
                    c++;
                }
                return c;
            }
            //take 1
            int n1 = (s[1] != '0') ? decode(s.substr(1), pos + 1) : 0;
            // take 2
            int take2 = stoi(s.substr(0, 2));
            int n2 = (take2 < 27 && take2 > 9) ? decode(s.substr(2), pos + 2) : 0;
            return n1 + n2;
        }
    };

    class Solution1 {
    public:
        int numDecodings(string s) {
            int l = s.length();
            if (s.empty())
                return 0;

            int dp1=0, dp2=0;
            if (s[0]!='0')
                dp1=1;
            else
                return 0;

            if (s.length()==1)
                return dp1;

            if (s.length()>1) {
                if (stoi(s.substr(0,2)) < 27) {
                    dp2++;
                }
                if (s[1]!='0')
                    dp2++;
            }
            for (int i=2;i < l; i++) {
                int n1 = 0,n2=0;
                if (s[i]!='0') {
                    n1 = dp2;
                }
                int take2 = stoi(s.substr(i-1, 2));
                if (take2<27&&take2>9) { // 和前一个字符组合有效
                    n2 = dp1;
                }
                int tmp = dp2;
                dp2 = n1+n2;
                dp1 = tmp;
            }
            return dp2;
        }
    };

    class Solution2 {
    public:
        int numDecodings(string s) {
            int n = s.size();
            if(n == 0 || s[0] == '0') return 0;
            if(n == 1) return 1;
            int res = 0,fn_1 = 1,fn_2 = 1;
            for(int i = 1;i < n;i++){
                int temp = fn_1;
                if(isValid(s[i])&&isValid(s[i-1],s[i]))  res+=fn_1+fn_2;
                if(!isValid(s[i])&&isValid(s[i-1],s[i])) res+=fn_2;
                if(isValid(s[i])&&!isValid(s[i-1],s[i])) res+=fn_1;
                if(!isValid(s[i])&&!isValid(s[i-1],s[i]))  return 0;
                fn_1 = res;
                fn_2 = temp;
                res = 0;
            }
            return fn_1;
        }
        bool isValid(char a,char b){
            return a == '1'||(a == '2' && b <='6');
        }
        bool isValid(char a){
            return a != '0';
        }
    };
}

    /*
     * public int numDecodings(String s) {
        int n = s.length();
        if (n == 0) return 0;

        int[] memo = new int[n+1];
        memo[n]  = 1;
        memo[n-1] = s.charAt(n-1) != '0' ? 1 : 0;

        for (int i = n - 2; i >= 0; i--)
            if (s.charAt(i) == '0') continue;
            else memo[i] = (Integer.parseInt(s.substring(i,i+2))<=26) ? memo[i+1]+memo[i+2] : memo[i+1];

        return memo[0];
    }
     */




DEFINE_CODE_TEST(091_decodeways)
{
    Solution1 obj;
    {
        VERIFY_CASE(obj.numDecodings("1168963884134125126536966946586868418993819971673459188478711546479621135253876271366851168524933185"),622080);
    }
    {
        string s = "1";
        VERIFY_CASE(obj.numDecodings(s),1);
    }
    {
        string s = "301";
        VERIFY_CASE(obj.numDecodings(s),0);
    }
    {
        string s = "30";
        VERIFY_CASE(obj.numDecodings(s),0);
    }
    {
        string s = "1111";//1,1,1,1 / 11,11 / 1,1,11/ 11,1,1 /1,11,1
        VERIFY_CASE(obj.numDecodings(s),5);
    }
    {
        string s = "12";
        VERIFY_CASE(obj.numDecodings(s),2);
    }
    {
        string s = "123";
        VERIFY_CASE(obj.numDecodings(s),3);
    }
    {
        string s = "";
        VERIFY_CASE(obj.numDecodings(s),0);
    }


    {
        string s = "1009";
        VERIFY_CASE(obj.numDecodings(s),0);
    }

    {
        string s = "1109"; // 1,10,9
        VERIFY_CASE(obj.numDecodings(s),1);
    }

    {
        string s = "0";
        VERIFY_CASE(obj.numDecodings(s),0);
    }

    {
        string s = "10";
        VERIFY_CASE(obj.numDecodings(s),1);
    }

    {
        string s = "27";
        VERIFY_CASE(obj.numDecodings(s),1);
    }

    {
        string s = "20";
        VERIFY_CASE(obj.numDecodings(s),1);
    }


    {
        string s = "03";
        VERIFY_CASE(obj.numDecodings(s),0);
    }
    {
        string s="8299152987184352183335613793611738246622952882892165423687431814339833963464637792247791375416898193";
        VERIFY_CASE(obj.numDecodings(s),165888);
    }
}