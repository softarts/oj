//
// Created by rui.zhou on 3/14/2019.
//

/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2]
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
 */

#include <codech/codech_def.h>
using namespace std;
//找出最小的数字，因为没有重复数字，所以用二分法找出最后2个数
namespace lc153 {
    class Solution {
    public:
        int findMin(vector<int>& nums) {
            //if (nums.empty()) return 0;
            int left=0,right=nums.size()-1;
            while (left<=right && right-left>1) { //要求必须有2个数
                int mid=(left+right)/2;
                if (nums[mid]<nums[left]) {  //发生移位，最小数在左侧
                    right=mid;
                } else {
                    if (nums[left]<nums[mid] && nums[mid]<nums[right]) {
                        return nums[left];  //按顺序，最小数就是left
                    } else {
                        left=mid; //否则往右寻找
                    }
                }
            }
            return min(nums[left],nums[right]);
        }
    };
}

DEFINE_CODE_TEST(153_find_mininum_inrotatedsortarray)
{
    lc153::Solution obj;
    {
        vector<int> nums{3,4,5,1,2};
        VERIFY_CASE(obj.findMin(nums),1);
    }
    {
        vector<int> nums{4,5,6,7,0,1,2};
        VERIFY_CASE(obj.findMin(nums),0);
    }
}
