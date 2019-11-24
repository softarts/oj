//
// Created by rui zhou on 2019-11-22.
//

// 二进制中1的个数
//思路，单纯的移位，O(N)
//2 自身和（-1）&
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int numberof1(int n) {
            int ans = 0;
            while (n) {
                ans++;
                n = n & (n-1);
            }
            return ans;
        }
    };
}


DEFINE_CODE_TEST(010_numberof1)
{
    Solution obj;
    {
        VERIFY_CASE(obj.numberof1(3),2);
        VERIFY_CASE(obj.numberof1(8),1);
    }
}


