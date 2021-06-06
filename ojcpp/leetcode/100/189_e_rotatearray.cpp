//
// Created by rui.zhou on 1/29/2019.
//

/*https://leetcode.com/problems/rotate-array/
 * Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
哪里考过了?
 方法较笨
 TODO
 */
#include <codech/codech_def.h>
#include <codech/algo_common.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int l=nums.size();
            k=k%l;  // 比较傻的方法,相当于移动K次,
            for (int i=1;i<=k;i++) {
                //int moving = nums[l-1];
                int tmp = nums[l-1];  //记住最后一个字符,每个逐个右移，太傻了
                for (int j=l-2;j>=0;j--) {
                    nums[j+1] = nums[j];
                }
                nums[0] = tmp;
            }
        }
    };
    // 需要额外空间
    class Solution1 {
    public:
        void rotate(vector<int>& nums, int k) {
            vector<int> t = nums;
            for (int i = 0; i < nums.size(); ++i) {
                nums[(i + k) % nums.size()] = t[i];
            }
        }
    };
    // 1 2 3 4 5 6 7
    // 4 3 2 1 5 6 7
    // 4 3 2 1 7 6 5
    // 5 6 7 1 2 3 4
    // 妙!!!
    class Solution2 {
    public:
        void rotate(vector<int>& nums, int k) {
            if (nums.empty() || (k %= nums.size()) == 0) return;
            int n = nums.size();
            reverse(nums.begin(), nums.begin() + n - k);
            reverse(nums.begin() + n - k, nums.end());
            reverse(nums.begin(), nums.end());
        }
    };

}

DEFINE_CODE_TEST(189_rotatearray)
{
    Solution obj;
    {
        vector<int> nums{1,2,3,4,5,6,7};
        obj.rotate(nums,3);
        VERIFY_CASE(PRINT_VEC(std::move(nums)),"5 6 7 1 2 3 4");
    }
    {
        vector<int> nums{-1,-100,3,99};
        obj.rotate(nums,2);
        VERIFY_CASE(PRINT_VEC(std::move(nums)),"3 99 -1 -100");
    }
}