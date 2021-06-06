//
// Created by Rui Zhou on 12/4/18.
//

/*
 * https://leetcode.com/problems/maximum-product-subarray/description/
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
 assume all integer(neg & pos),
 it is a DP issue....
 找出连续子数组的乘积最大,返回该乘积
 思路
 问题是负数也要记住

 */


#include <codech/codech_def.h>

using namespace std;

namespace {
    class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            if (nums.empty())
                return 0;
            int maxSum = nums[0], minSum = nums[0];
            int ret = nums[0];
            for (int i=1;i<nums.size();i++) {
                int tmp = maxSum;
                maxSum = max(nums[i], max(minSum * nums[i], maxSum * nums[i]));
                minSum = min(nums[i], min(minSum * nums[i], tmp * nums[i]));
                ret = max(maxSum, ret);
            }
            return ret;
        }
    };

    class Solution1 {
    public:
        int maxProduct(vector<int>& nums) {
            if (nums.empty())
                return 0;
            vector<int> mx(nums.size(),0);
            vector<int> mn(nums.size(),0);
            mx[0]=nums[0];
            mn[0]=nums[0];

            //int maxSum = nums[0], minSum = nums[0];
            int ret = nums[0];

            for (int i=1;i<nums.size();i++) {
                mx[i] = max(nums[i], max(mx[i-1]*nums[i],mn[i-1]*nums[i]));
                mn[i] = min(nums[i], min(mn[i-1]*nums[i],mx[i-1]*nums[i]));
                ret = max(mx[i], ret);
            }
            return ret;
        }
    };
}


DEFINE_CODE_TEST(152_maximum_product_subarray)
{
    Solution1 obj;
    {
        vector<int> nums{2,3,-2,4};
        VERIFY_CASE(obj.maxProduct(nums), 6);
    }
    {
        vector<int> nums{-4,-3,-2};
        VERIFY_CASE(obj.maxProduct(nums), 12);
    }
}