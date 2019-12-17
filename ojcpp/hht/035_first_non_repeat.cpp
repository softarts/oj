//
// Created by rui zhou on 08/05/19.
//

#include <codech/codech_def.h>
using namespace std;

// AMAZON 考题,f*
// GS 1st
// 使用hashmap，遍历两次

namespace {
    class Solution {
    public:
        char firstNonRepeat(string s) {
            unordered_map<char,int> m;
            for (auto &it:s) {
                m[it]+=1;
            }

            for (auto &it:s) {
                if (m[it]==1)
                    return it;
            }
            return '\0';
        }
    };
}

DEFINE_CODE_TEST(hht_035_firstnonrepeat)
{
    Solution obj;
    {
        VERIFY_CASE(obj.firstNonRepeat("abaccedff"),'b');
        VERIFY_CASE(obj.firstNonRepeat(""),'\0');
        VERIFY_CASE(obj.firstNonRepeat("abca"),'b');

    }

}