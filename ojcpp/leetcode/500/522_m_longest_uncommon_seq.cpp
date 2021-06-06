//
// Created by rui.zhou on 3/17/2019.
//

/*
 * Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].


 Basically this solution relies on two things:
1- If a substring of any string in the list is an uncommon subsequence,
 then so is the string. So the longest uncommon substring, if there is one, has to be a whole string from the list.
2- A string can only be a subsequence of another string that is the same size (if it's the same string) or longer.

So, what we do is sort the strings by size (in decreasing order) and then, starting from the longest string,
 check if there are any other strings of it's length or higher that it is a subsequence of. If there isn't then that is the max uncommon subsequence.

找出最长非公共子序列。公共子序列的定义是一个字符串可由另一个字符串删除某些字符得到。
如果在一组字符串中，某一个字符串不是任何另外的字符串的公共子序列，那么这就是它是全组的非公共子序列。找出最长的长度。
 直接用暴力法
 先排序，从大到小，然后一次看每一个str是否和数组里的有subseq关系
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        //检查是否subsequence的套路，通过删除字符
        // aa is aaa subseq, abc is addbddc subseq
        bool check_subsequence(string str1, string str2){
            int i = 0; int j = 0;
            while (i < str1.size() && j < str2.size()){
                if (str1[i] == str2[j])
                    i++;
                j++;
            }
            return (i == str1.size());
        }

        int findLUSlength(vector<string>& strs) {
            std::sort(strs.begin(), strs.end(), [](string a, string b){return a.size() > b.size();});
            for (int i = 0; i < strs.size(); i++){
                bool is_subsequence = false;
                for (int j = 0; j < strs.size() && (j < i || strs[i].size() == strs[j].size()); j++){
                    //只和大于等于自己长度的str比较,str[i].length <= str[j].length
                    //如果自己的长度大于对方，那就不存在subseq了!
                    if (i != j && check_subsequence(strs[i], strs[j])){
                        is_subsequence = true;
                        break;
                    }
                }
                if (!is_subsequence)
                    return strs[i].size();
            }
            return -1;
        }
    };


}

DEFINE_CODE_TEST(522_longest_uncommonseq2)
{
    Solution obj;
    {
        vector<string> strs{"aaa","aaa","aa"};
        VERIFY_CASE(obj.findLUSlength(strs),-1);
    }
    {
        vector<string> strs{"abaa", "cdc", "eae"};
        VERIFY_CASE(obj.findLUSlength(strs),4);
    }
    {
        vector<string> strs{"aba", "cdc", "eae"};
        VERIFY_CASE(obj.findLUSlength(strs),3);
    }


}