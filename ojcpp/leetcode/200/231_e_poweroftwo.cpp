//
// Created by Rui Zhou on 30/3/18.
//

/*
 * https://leetcode.com/problems/power-of-two/description/
 *
 */

#include <codech/codech_def.h>

using namespace std;
//这题目好像不对
//namespace yt {
//    int Count(const vector<int>& nums)
//    {
//        int count = 0;
//        for (int i = 0;i < nums.size();i++) {
//            int sum = nums[i];
//            if (sum>=7 && (sum  % 7 ==0))
//                count++;
//            for (int j = i+1;j<nums.size();j++) {
//                sum += nums[j];
//                if (sum >= 7 && (sum % 7 ==0)) {
//                    count++;
//                }
//            }
//        }
//        return count;
//    }
//}


// 判断一个数是不是2的幂
// 最高位是1，后面都是0
namespace {
    class Solution {
    public:
        bool isPowerOfTwo(int n) {
            return (n&(n-1))==0;

        }
    };
}


DEFINE_CODE_TEST(231_poweroftwo)
{

    Solution obj;
    {
        VERIFY_CASE(obj.isPowerOfTwo(1),true);
        VERIFY_CASE(obj.isPowerOfTwo(2),true);
    }
}
