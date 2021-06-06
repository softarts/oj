//
// Created by rui.zhou on 2/6/2019.
//

/*
 * Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
思路
 1.使用hashmap记录已有的数字，然后从小到大遍历。不是O(1) space
 2.不使用hashmap的话，如何做到O(1) space？ 使用priority queue的话是NlogN?？

 所以我们需要另想一种解法，既然不能建立新的数组，那么我们只能覆盖原有数组，我们的思路是把1放在数组第一个位置nums[0]，
 2放在第二个位置nums[1]，即需要把nums[i]放在nums[nums[i] - 1]上，
 那么我们遍历整个数组，如果nums[i] != i + 1, 而nums[i]为整数且不大于n，另外nums[i]不等于nums[nums[i] - 1]的话，
 我们将两者位置调换，如果不满足上述条件直接跳过，最后我们再遍历一遍数组，如果对应位置上的数不正确则返回正确的数，

 如果不能用hashmap,必须找一个方法来保存找出的数字，题目描述比较简单，所以解法可能很巧妙。
 上面的调换显得过于复杂，原题没有说不能修改原数组，只需要保证，将每个数值对应的index上的数字设置一个flag,然后在遍历中识别出这个flag即可。


 */

#include <codech/codech_def.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] <= 0){
                nums[i] = INT_MAX;
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            int tmp = abs(nums[i])-1;
            if(tmp < nums.size())
                if(nums[tmp] > 0)
                    nums[tmp] = -nums[tmp];

        }

        int ret = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] >= 0){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

DEFINE_CODE_TEST(041_firstmissingpositive)
{
    Solution obj;
    {
        vector<int> nums{3,4,-1,1};
        VERIFY_CASE(obj.firstMissingPositive(nums),2);
    }
    {
        vector<int> nums{1,2,0};
        VERIFY_CASE(obj.firstMissingPositive(nums),3);
    }
    {
        vector<int> nums{7,8,9,11,12};
        VERIFY_CASE(obj.firstMissingPositive(nums),1);
    }

}

