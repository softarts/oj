//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/majority-element/description/
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
 best answer is hard
 */

#include <codech/codech_def.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

namespace {
    //排序的做法,中点即超过一半的数字
    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            sort(nums.begin(), nums.end());  // N*LogN
            int x = nums[nums.size()/2];
            return x;
        }
    };

    // still slow hashtabel
    // 使用hash,需要O(N)空间和O(N) 复杂度
    class Solution1 {
    public:
        int majorityElement(vector<int> &nums) {
            unordered_map<int, int> counts;  // O(N)
            for (auto &&iter : nums) {
                if (++counts[iter] > nums.size() / 2) {
                    return iter;
                }
            }
            return 0;
        }
    };

    class Solution2 {
    public:
        //Boyer-Moore Majority Vote Algorithm
        //http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
        //count 初始为1
        //如果与前面的数相同,count++,否则count--,count为0时重新选择新的数
        //当前跟踪的数prev,如果其count>0,那就继续处理它
        //这个前提是必然有一个数多于一半，否则算法不成立
        int majorityElement(vector<int>& nums) {
            int count = 1;
            int prev = nums[0];
            for (int i=1; i < nums.size(); i++) {
                if (nums[i]==prev) {
                    count++;
                } else {
                    if (--count == 0) {
                        prev = nums[i];
                        count = 1;
                    }
                }
            }
            return prev;
        }

    };

}


DEFINE_CODE_TEST(169_majority_elements)
{
    Solution2 obj;
    {
        vector<int> nums{3,3,2,3,1,3,2,3};
        VERIFY_CASE(obj.majorityElement(nums),3);
    }

    {
        vector<int> nums{3,2,3};
        VERIFY_CASE(obj.majorityElement(nums),3);
    }

}

