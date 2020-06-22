//
// Created by rui zhou on 2020-06-19.
//

/*
 *     Given a non-empty array of integers, return the third maximum number in this array.
 *     If it does not exist, return the maximum number. The time complexity must be in O(n).

 */

#include <codech/codech_def.h>
using namespace std;
namespace {
    class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            long num1=LONG_MIN,num2=LONG_MIN,num3=LONG_MIN;

            auto mysort =[&](int v) {
                if (v==num1||v==num2||v==num3) return;
                if (v>num1) {
                    num3 = num2;
                    num2 = num1;
                    num1 = v;
                } else if (v>num2) {
                    num3 = num2;
                    num2 = v;
                } else if (v>num3) {
                    num3 = v;
                }
            };

            for (auto v:nums) {
                mysort(v);
            }
            if (num3!=LONG_MIN) {
                return num3;
            } else {
                return num1;
            }
        }
    };
}

DEFINE_CODE_TEST(414_thirdmax)
{
    Solution obj;
    {
        vector<int> m = {2, 2, 3, 1};
        VERIFY_CASE(obj.thirdMax(m),1);
    }
    {
        vector<int> m = {1,2,-2147483648};
        VERIFY_CASE(obj.thirdMax(m),-2147483648);
    }

}


