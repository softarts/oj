//
// Created by rui zhou on 25/03/18.
//

/*
 * https://leetcode.com/problems/sort-colors/description/
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
红白蓝三色，相同颜色相邻，并且依次是0-1-2
 */

#include <codech/codech_def.h>
#include <vector>
#include <codech/algo_common.h>

using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        // one pass, 由于顺序必须是0 -1 -2 ，所以每次写1的时候必须往后面写一个2,尽管可能被冲掉(除非真的有2，把b的位置往后挪了)
        void sortColors(vector<int> &nums) {
            int r = 0, w = 0, b = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    nums[b++] = 2;
                    nums[w++] = 1;
                    nums[r++] = 0;
                } else if (nums[i] == 1) {
                    nums[b++] = 2;
                    nums[w++] = 1;
                } else if (nums[i] == 2) {
                    nums[b++] = 2;
                }
            }
        }
    };

    // 2 pass,先记下个数，再写满次数
    class Solution0 {
    public:
        void sortColors(vector<int>& nums) {
            int c[]={0,0,0};
            for (int i = 0; i < nums.size(); i++) {
                c[nums[i]]++;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (i < c[0])
                    nums[i] = 0;
                else if (i-c[0]<c[1])
                    nums[i] = 1;
                else if (i-c[0]-c[1]<c[2])
                    nums[i] = 2;
            }
        }


    };
}


DEFINE_CODE_TEST(075_sortcolors)
{
    Solution obj;
    {
        vector<int> nums{0,1,2,0,1,2,0,1,2,2,0};
        obj.sortColors(nums);
        VERIFY_CASE(PRINT_VEC(std::move(nums)), "0 0 0 0 1 1 1 2 2 2 2");
    }
}

