//
// Created by rui zhou on 2019-11-05.
//

/*
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */


#include <codech/codech_def.h>
#include <sstream>

using namespace std;

namespace {
    class Solution {
    public:
        string reverseWords(string s) {
            string ans;
            stringstream ss(s);
            string tmp;
            while (getline(ss,tmp,' ')) {
                std::reverse(tmp.begin(),tmp.end());
                ans+=tmp;
                ans+=' ';
            }
            return ans.empty()?"":ans.substr(0,ans.length()-1);
        }
    };
}
