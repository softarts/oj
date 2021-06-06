//
// Created by rui zhou on 20/02/19.
//

/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    //无法解决 ()(()这种情况，还是要找出一个独特的解法。
//    int longestValidParentheses(string s) {
//        int maxLen = 0;
//        int curLen = 0;
//        int curSum = 0;
//        for (int i=0; i < s.length(); i++) {
//            curSum += (s[i]=='('?1:-1);
//            if (curSum<0) {
//                curSum = 0;
//                curLen = 0;
//                continue;
//            }
//            if (s[i]==')') {
//                curLen+=2;
//                maxLen = max(maxLen, curLen);
//            }
//
//        }
//        return maxLen;
//    }
    int longestValidParentheses(string s) {
        stack<char> st;
        vector<int> vec;
        for (int i=0; i < s.length(); i++) {
            if (s[i]==')' && !st.empty() && st.top()=='(') { // st.empty() 条件
                st.pop();
                vec.pop_back();
            } else {
                st.push(s[i]);
                vec.push_back(i);
            }
        }
        vec.push_back(s.length());
        int maxLen=0;
        int prev=-1;
        for (int i=0;i<vec.size();i++){
            maxLen= max(vec[i]-prev-1,maxLen);
            prev=vec[i];
        }
        return maxLen;
    }
};


DEFINE_CODE_TEST(032_longestvalidparenthese)
{
    Solution obj;
    {
        VERIFY_CASE(obj.longestValidParentheses("(()"),2);
        VERIFY_CASE(obj.longestValidParentheses(")()())"),4);
        VERIFY_CASE(obj.longestValidParentheses("()"),2);
        VERIFY_CASE(obj.longestValidParentheses("()"),2);
        VERIFY_CASE(obj.longestValidParentheses(""),0);
        VERIFY_CASE(obj.longestValidParentheses("()(()"),2);
        VERIFY_CASE(obj.longestValidParentheses(")()())"),4);

    }

}