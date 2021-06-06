//
// Created by Rui Zhou on 3/4/18.
//

/*
 * https://leetcode.com/problems/find-peak-element/description/
 * A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
对数的一般属于binary search，注意到相邻的元素均不相等，
二分，比较两个中值，不会出现 4,5,1,1,1,1,1,1, 这个情况，否则无法二分
 */


#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1]) // 在左侧
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

DEFINE_CODE_TEST(162_findpeak)
{
    Solution obj;
    {
        vector<int> nums{1,2,3,1};
        VERIFY_CASE(obj.findPeakElement(nums),2);

    }
}


