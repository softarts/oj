//
// Created by Rui Zhou on 30/3/18.
//

/*
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

意思是返回当前的index,但要使用比O(N)更好的算法
must be better than O(N), solved by binary_search
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    /*   完全不对
    int search0(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int prev = nums[0];
        int pivot = 0;
        int idx = -1;
        for (int i=0;i < nums.size(); i++) {
            if (nums[i] < prev) {
                pivot = i;
            }
            if (nums[i] == target) {
                idx = i;
            }
            prev = nums[i];
        }

        if (pivot==0)
            return idx;
        if (idx <pivot && idx >=0) {
            idx = idx + pivot;
        } else if (idx>=pivot){
            int offset = nums.size()-pivot;
            idx = idx - offset;
        }
        return idx;
    }*/



    int search0(vector<int>& nums, int target) {
        int lo = 0, hi = int(nums.size()) - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }

    // 4 5 6 7 0 1 2
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while (lo <= hi) {
            int mid = (hi+lo)/2;
            if (nums[mid]==target)
                return mid;
            if (nums[mid] > nums[hi]) { // rotation right part
                if (target < nums[mid] && target >= nums[lo]) {
                    hi = mid - 1;
                } else {  // 4 5 6 7 8 9 11(mid) 12 13 14 0 1 2 3
                    lo = mid + 1;
                }
            } else if (nums[mid] < nums[lo]) { // rotation left part
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid+1;
                } else {
                    hi = mid - 1;
                }
            } else {  // no rotation
                if (target > nums[mid]) {
                    lo = mid+1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }


};

DEFINE_CODE_TEST(033_search_in_rotated_array)
{
    Solution obj;

    {
        vector<int> nums{3,5, 1};
        VERIFY_CASE(obj.search(nums,3),0);
    }
    {
        vector<int> nums{3,1};
        VERIFY_CASE(obj.search(nums,1),1);
    }
    {
        vector<int> nums{1,3};
        VERIFY_CASE(obj.search(nums,1),0);
    }


    {
        vector<int> nums{1};
        VERIFY_CASE(obj.search(nums,1),0);
    }
    {
        vector<int> nums{4,5,6,7,0,1,2,3};
        VERIFY_CASE(obj.search(nums,1),5);
    }

}