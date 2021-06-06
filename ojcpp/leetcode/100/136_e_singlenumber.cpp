//
// Created by rui zhou on 23/03/18.
//

/*
 * https://leetcode.com/problems/single-number/description/
 * Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Seen this question in a real interview before?

 */

#include <codech/codech_def.h>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int result = nums[0];

        for (int i = 1;i<nums.size();i++) {
            result = result^nums[i];
        }
        return result;
    }
};

DEFINE_CODE_TEST(136_singlenumber)
{
    Solution obj;
    {
        vector<int> nums{1,1,2,2,3,3,4};
        VERIFY_CASE(obj.singleNumber(nums), 4);
    }

}