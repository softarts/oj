//
// Created by rui zhou on 18/02/19.
//

/*
 *Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 求所有字符串最长的公共前置字符串，即前面的字符都一样，最长能到多少
 根本不需要排序，O(N^2)的算法
 */


#include <codech/codech_def.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t minLen = INT_MAX;
        if (strs.size()<1)
            return "";
        for (int i=0;i<strs.size();i++) {
            minLen = std::min(strs[i].length(),minLen);
        }

        for (int i=0;i<=minLen;i++) {
            char c = strs[0][i];int j=1;
            while (j<strs.size() && strs[j][i]==c) {
                j++;
            }
            if (j!=strs.size())
                return strs[0].substr(0,i);
        }
        return strs[0].substr(0,minLen);
    }
};

DEFINE_CODE_TEST(014_longestcommonprefix)
{
    Solution obj;
    {
        vector<string> strs{"flower","flow","flight"};
        VERIFY_CASE(obj.longestCommonPrefix(strs),"fl");
    }
    {
        vector<string> strs{"dog","racecar","car"};
        VERIFY_CASE(obj.longestCommonPrefix(strs),"");
    }
    {
        vector<string> strs{"dog"};
        VERIFY_CASE(obj.longestCommonPrefix(strs),"");
    }
    {
        vector<string> strs{""};
        VERIFY_CASE(obj.longestCommonPrefix(strs),"");
    }

}