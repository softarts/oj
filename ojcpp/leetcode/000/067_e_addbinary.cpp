//
// Created by rui.zhou on 2019/9/11.
//

/*
 * Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        string addBinary(string a, string b) {
            int maxLen = max(a.length(),b.length());
            int idx = 0;
            string ans;
//            while (idx<maxLen) {
//                int ida = a.length() - idx - 1;
//                int v = ida<a.length()?a[]:0 + idx<b.length()?b[idx]:0;
//                int carry = v>1?1:0;
//                if (v==2) v = 0;
//                ans += to_string(v);
//                idx--;
//            }
//            std::reverse(ans.begin(),ans.end());
            return ans;
        }
    };
}