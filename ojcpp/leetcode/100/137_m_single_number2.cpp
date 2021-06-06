//
// Created by rui.zhou on 3/14/2019.
//

/*
 * Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

 TODO
 通用的思路，生成只有某个Bit为1的数字，去做&，结果sum % 3;如果不为0则把该位置1
 凡是涉及到最高位1都要考虑int64_t避免溢出
 */
#include <codech/codech_def.h>
using namespace std;

namespace lc137 {
    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int64_t ret=0;
            for (int i=0;i<32;i++) {
                int thebit=1<<i;
                int64_t sum=0;
                for (auto iter:nums) {
                    sum+= (iter & thebit);
                }
                int mod = sum%3;
                if (mod!=0) {
                    ret|=thebit;
                }
            }
            return ret;
        }
    };
}

DEFINE_CODE_TEST(137_singlenumber2)
{
    lc137::Solution obj;
    {
        vector<int> nums{-2,-2,1,1,-3,1,-3,-3,-4,-2};
        VERIFY_CASE(obj.singleNumber(nums),-4);
    }
    {
        vector<int> nums{2,2,3,2};
        VERIFY_CASE(obj.singleNumber(nums),3);
    }
    {
        vector<int> nums{0,1,0,1,0,1,99};
        VERIFY_CASE(obj.singleNumber(nums),99);
    }
}

