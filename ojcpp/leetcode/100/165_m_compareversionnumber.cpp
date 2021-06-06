//
// Created by rui.zhou on 9/30/2019.
//

/*
 *Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.



Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"


Note:

Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.

 按位比较version，并不是很难？用python方便，直接split成多个tokens
参看python 代码
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int parseNumber(string input){
            int n(0);
            for(const char c: input){
                n = n*10 + (c - '0');
            }
            return n;
        }

        int compareVersion(string version1, string version2) {
            size_t p1=0,p2=0;
            while (p1<version1.length() || p2<version2.length()) {
                string  v1,v2;
                while (p1<version1.length() && version1[p1]!='.' ) {
                    v1.push_back(version1[p1]);
                    p1++;
                }
                while (p2<version2.length() && version2[p2]!='.') {
                    v2.push_back(version2[p2]);
                    p2++;
                }
                int n1 = parseNumber(v1);
                int n2 = parseNumber(v2);

                if(n1 > n2) return 1;
                if(n1 < n2) return -1;
                p1++;
                p2++;
            }
            return 0;
        }
    };
}

DEFINE_CODE_TEST(165_compareversion) {
    Solution obj;
    {
        VERIFY_CASE(obj.compareVersion("1","1.0"), 0);
        VERIFY_CASE(obj.compareVersion("0.1","1.1"), -1);
    }
}
