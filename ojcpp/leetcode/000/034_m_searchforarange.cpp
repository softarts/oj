//
// Created by Rui Zhou on 7/4/18.
//

/*
 * https://leetcode.com/problems/search-for-a-range/description/
 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>
#include <algorithm>

using namespace std;
using namespace CODECH;

class Solution {
public:
    //no less than target (>=target)
    int lower_bound(vector<int> &nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = (end-start)/2+start;
            if (nums[mid] < target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return start;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = nums.size();
        int idx1 = lower_bound(nums, target);
        int idx2 = lower_bound(nums, target+1)-1;
        if (idx1<l && nums[idx1] == target) {
            return {idx1,idx2};
        } else {
            return {-1,-1};
        }
    }
};

DEFINE_CODE_TEST(034_search_for_a_range)
{
    Solution obj;
    {
        vector<int> nums{5, 7, 7, 8, 8, 10};
        VERIFY_CASE(PRINT_VEC(obj.searchRange(nums, 8)),"3 4");
    }
}