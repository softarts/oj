//
// Created by rui.zhou on 3/16/2019.
//

/*
 * Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
namespace {
    class Solution {
    public:
        bool checkValidString(string s) {
            int low = 0;
            int high = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '(') {
                    low++;
                    high++;
                } else if (s[i] == ')') {
                    if (low > 0) {
                        low--;
                    }
                    high--;
                } else {
                    if (low > 0) {
                        low--;
                    }
                    high++;
                }
                if (high < 0) {
                    return false;
                }
            }
            return low == 0;
        }
    };
    // 从左到右，*看作(,(个数要大于等于)
    class Solution1 {
    public:
        bool checkValidString(string s) {
            int cnt=0;
            for (int i=0;i<s.length();i++) {
                if (s[i]=='(' || s[i]=='*') {
                    cnt++;
                } else if (s[i]==')') {
                    if (cnt>0)
                        cnt--;
                    else
                        return false;
                }
            }
            cnt = 0;
            for (int i=s.length()-1;i>=0;i--) {
                if (s[i]==')' || s[i]=='*') {
                    cnt++;
                } else if (s[i]=='(') {
                    if (cnt>0)
                        cnt--;
                    else
                        return false;
                }
            }
            return true;
        }
    };
}

DEFINE_CODE_TEST(678_valid_parenthesis)
{
    Solution obj;
    {
        VERIFY_CASE(obj.checkValidString("(*))"),true);
        VERIFY_CASE(obj.checkValidString("(*)"),true);
        VERIFY_CASE(obj.checkValidString("(*)("),false);

    }

}