//
// Created by rui.zhou on 3/10/2019.
//

/*
 * Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 去掉多于2次的数字,返回长度

 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace lc080 {
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int r=1,w=1,end=nums.size();
            if (nums.size()<3)
                return nums.size();
            int w_count=1;
            int r_count=0;

            while (w<end && w_count<2 && nums[w]==nums[w-1]) {
                w++;w_count++;
            }
            while (r<end && nums[r]==nums[r-1]) {
                r++;
            }

            for (int i=r;i<end;i++) {
                if (nums[i]!=nums[i-1]) {
                    r_count=0;
                }
                if (r_count<2) {
                    nums[w++]=nums[i];
                    r_count++;
                }
            }
            return w;
        }
    };

    // 精简了代码,如果没要求in-place,可以直接删除该元素
    // 从idx=1开始，如果和前一个相等,则检查计数
    class Solution1 {
    public:
        int removeDuplicates(vector<int>& nums) {
            int r=1,w=1,end=nums.size();
            if (nums.size()<3)
                return nums.size();
            int r_count=1;
            for (int i=r;i<end;i++) {
                if (nums[i]==nums[i-1]) {
                    if (r_count<2) {//相等,但是未到2次
                        nums[w++]=nums[i];
                        r_count++;
                    }
                } else {
                    nums[w++]=nums[i];
                    r_count=1;
                }

            }
            return w;
        }
    };

    class Solution2 {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size()<3)
                return nums.size();
            int w=1;
            int count = 1; //allow 1 duplicate
            for (int i=1;i<nums.size();i++) {
                if (nums[i]==nums[i-1] && count==0) {
                } else { //不等，可以写
                    if (nums[i]==nums[i-1]) count--;
                    else count=1;
                    nums[w++]=nums[i];
                }
            }
            return w;
        }
    };
}

DEFINE_CODE_TEST(080_remove_duplicate_from_sorted_array)
{
    lc080::Solution2 obj;
    {
        vector<int> nums{1,1,1,2};
        VERIFY_CASE(obj.removeDuplicates(nums),3);
    }
    {
        vector<int> nums{1,1,1};
        VERIFY_CASE(obj.removeDuplicates(nums),2);
    }
    {
        vector<int> nums{1,1,1,2,2,3};
        VERIFY_CASE(obj.removeDuplicates(nums),5);
    }
    {
        vector<int> nums{0,0,1,1,1,1,2,3,3};
        VERIFY_CASE(obj.removeDuplicates(nums),7);
        //VERIFY_CASE(PRINT_VEC(std::move(nums)),"0 0 1 1 2 3 3")
    }
    {
        vector<int> nums{1,2};
        VERIFY_CASE(obj.removeDuplicates(nums),2);
    }
    {
        vector<int> nums{1};
        VERIFY_CASE(obj.removeDuplicates(nums),1);
    }
    {
        vector<int> nums{};
        VERIFY_CASE(obj.removeDuplicates(nums),0);
    }

}