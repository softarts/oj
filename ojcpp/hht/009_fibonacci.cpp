//
// Created by rui zhou on 2019-11-22.
//

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int fibonacci(int n) {
            int f0=0;
            int f1=1;
            int f = 0;
            if (n=0) return 0;
            if (n==1) return 1;
            for (int i=2;i<=n;i++) {
                f = f0+f1;
                f0 = f1;f1=f;
            }
            return f;
        }
    };
}


DEFINE_CODE_TEST(010_numberof1)
{
    Solution obj;
    {
        VERIFY_CASE(obj.fibonacci(0),0);
        VERIFY_CASE(obj.fibonacci(1),1);
        VERIFY_CASE(obj.fibonacci(2),1);
        VERIFY_CASE(obj.fibonacci(3),2);
    }
}


