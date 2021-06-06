//
// Created by rui zhou on 18/02/19.
//

/*
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest
 * to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <codech/codech_def.h>

using namespace std;

class Solution {
public:
    vector<int> oridata;
    int threeSumClosest(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int len=nums.size();
        int closet = INT_MAX;
        int retSum = 0;
        for (int i=0;i<len-2;i++) {
            // 注意排除 连续相等的element, -1,-1,-1,2,2,2,2,
            // 或者使用set
            //if (i>0 && nums[i]==nums[i-1])
            //    continue;
            int l=i+1;
            int r=len-1;
            while (l<r) {
                int sum = nums[i]+nums[l]+nums[r];
                if (abs(sum-target)<closet) {
                    closet = abs(sum-target);
                    retSum = sum;
                }
                if (sum>target) { //不能抄015 target=0的例子
                    r--;
                } else if(sum<target) {
                    l++;
                } else { // equal
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while (l< len-1 &&nums[l]==nums[l+1]) l++;
                    while (r>0 && nums[r]==nums[r-1]) r--;
                    l++;r--;
                }
            }
        }
        return retSum;
    }


};

DEFINE_CODE_TEST(016_3sumcloset)
{
    Solution obj;
    {
        vector<int> nums{1,2,4,8,16,32,64,128};
        VERIFY_CASE(obj.threeSumClosest(nums,82),82);
    }
    {
        vector<int> nums{1,1,-1,-1,3};
        VERIFY_CASE(obj.threeSumClosest(nums,3),3);
    }
    {
        vector<int> nums{-1, 2, 1, -4};
        VERIFY_CASE(obj.threeSumClosest(nums,1),2);
    }
    {
        vector<int> nums{-1, 2, -4};
        VERIFY_CASE(obj.threeSumClosest(nums,1),-3);
    }
    {
        vector<int> nums{};
        VERIFY_CASE(obj.threeSumClosest(nums,1),0);
    }


}


