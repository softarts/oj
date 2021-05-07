/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

由于有重复数字

2，2，2，0，1

3 3 1 3  和 3 1 3 3 是无法区分的，所以必须顺序扫描

*/
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int findMin(vector<int>& nums) {
            int left = 0, right = nums.size()-1;
            while (left<=right && right-left>1) {
                int mid = (left+right)/2;
                if (nums[mid] < nums[left]) { // 发生移位，最小数必然在左侧
                    right=mid;
                } else { // 分情况
                    if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                        return minInorder(nums,left,right);
                    } else if (nums[left] <= nums[mid] && nums[mid] <= nums[right]) {
                        //不一定完全顺序，可能是 3 3 1 3 mid=3这种情况
                        //完全顺序，
                        //最小数就是left
                        return nums[left];
                    } else {
                        left = mid;
                    }
                }
            }
            return min(nums[left],nums[right]);
        }

        int minInorder(vector<int> &nums, int l, int r) {
            int n1 = nums[l];
            for (int i=l+1;i<=r;i++) {
                if (n1>nums[i])
                    return nums[i];
            }
            return n1;
        }
    };
}

DEFINE_CODE_TEST(154_find_mininum_inrotatedsortarray2)
{
    Solution obj;
     {
        vector<int> nums{3,3,1,3};
        VERIFY_CASE(obj.findMin(nums),1);
    }   

    {
        vector<int> nums{2,2,2,0,1};
        VERIFY_CASE(obj.findMin(nums),0);
    }    
}
