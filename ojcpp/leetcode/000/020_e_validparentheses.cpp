//
// Created by Rui Zhou on 9/4/18.
//

/*
 * https://leetcode.com/problems/valid-parentheses/description/
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


 */

#include <codech/codech_def.h>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty() || s.length()%2!=0)
            return false;
        stack<char> st;
        for (auto ch: s) {
            switch (ch) {
                case '(':
                case '{':
                case '[': st.push(ch);break;
                case ')': if (st.empty() || (!st.empty() && st.top()!='(')) return false;else st.pop();break;
                case '}': if (st.empty() || (!st.empty() && st.top()!='{')) return false;else st.pop();break;
                case ']': if (st.empty() || (!st.empty() && st.top()!='[')) return false;else st.pop();break;
            }
        }
        return st.empty();
    }
};


DEFINE_CODE_TEST(020_validparentheses)
{
    Solution obj;
    {
        string s = "[";
        VERIFY_CASE(obj.isValid(s),false);
    }
}