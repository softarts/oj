//
// Created by rui.zhou on 3/12/2019.
//

/*
 *Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
和153很类似，但153没有重复数字
 因此需要比较mid和left是否一样，一样的话只能left++
 把mid的位置画出几张图，看看都有什么可能
 */
#include <codech/codech_def.h>
using namespace std;
namespace lc081 {
    class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int left=0,right = nums.size()-1; //二分法一般需要include end
            while (left<=right) {
                int mid=(left+right)/2;
                if (nums[mid]==target)
                    return true;

                if (nums[mid]==nums[left]) {
                    left++;continue;
                }
                //两种图都得到一样的结果
                if (nums[mid] > nums[left]) {
                    if (target<nums[mid] && target>=nums[left])
                        right=mid-1;
                    else {
                        left=mid+1;
                    }
                }
                else {
                    if (nums[mid]<target && target<=nums[right])
                        left=mid+1;
                    else {
                        right=mid-1;
                    }
                }
            }
            return false;
        }
    };
}

DEFINE_CODE_TEST(081_searhc_rotated_sortarray)
{
    lc081::Solution obj;
    {
        vector<int> nums{1,3,1,1,1};
        VERIFY_CASE(obj.search(nums,3),true);
    }
    {
        vector<int> nums{1,1,3,1};
        VERIFY_CASE(obj.search(nums,3),true);
    }
    {
        vector<int> nums{2,5,6,0,0,1,2};
        VERIFY_CASE(obj.search(nums,0),true);
    }
    {
        vector<int> nums{2,5,6,0,0,1,2};
        VERIFY_CASE(obj.search(nums,3),false);
    }

}