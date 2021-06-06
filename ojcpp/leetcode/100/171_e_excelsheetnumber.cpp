//
// Created by rui.zhou on 1/28/2019.
//

/*
 * Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
 */

#include <codech/codech_def.h>
#include <locale>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
		std::locale loc;
        int map[26] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
        int sum = 0;
        for (auto c = s.begin();c!=s.end();++c) {
            auto uc = std::toupper(*c,loc);
            sum = sum*26;
            sum += map[uc-'A'];
        }
        return sum;
    }
};

DEFINE_CODE_TEST(171_excelsheetnumber)
{
    Solution obj;
    {
        std::string s = "S";
        VERIFY_CASE(obj.titleToNumber(s),19);
    }
    {
        std::string s = "AA";
        VERIFY_CASE(obj.titleToNumber(s),27);
    }
    {
        std::string s = "AB";
        VERIFY_CASE(obj.titleToNumber(s),28);
    }
}