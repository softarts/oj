//
// Created by Rui Zhou on 5/4/18.
//

/*
 *
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        const size_t end = str.length();
        int64_t ret = 0;
        int sign = 1;
        size_t pos = str.find_first_not_of(' ');
        if (pos == string::npos)
            return 0;

        if ((str[pos] == '+') || (str[pos] == '-'))
        {
            sign = str[pos] == '-'?-1:1;
            pos++;
        }


        while (pos<end && isdigit(str[pos]))
        {
            char ch = str[pos];
            ret = ret * 10 + (ch - '0');
            if (ret * sign >= INT_MAX) return INT_MAX;
            if (ret * sign <= INT_MIN) return INT_MIN;
            pos++;
        }

        return (int)ret*sign;

    }
};

DEFINE_CODE_TEST(008_stringtointeger)
{

}