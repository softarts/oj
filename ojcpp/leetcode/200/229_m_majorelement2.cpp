//
// Created by rui zhou on 2020-06-18.
//

#include <codech/codech_def.h>
using namespace std;

/**
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
 */

// 求所有多于1/3的元素,需要线性时间和O(1) space，所以不能用hash
// 实质就是最多3个数
// 如何记住有哪些元素
// 使用2个计数器,
namespace {
    class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int num1,num2,cnt1=0,cnt2=0,len=nums.size();
            //那么如果一个数出现次数超过1/3，则最后必然出现在统计的数中，
            //但是我们不能确定现在得到的这两个数出现次数是否超过1/3，因此最后需要再验证一下。
            //这是一个BM算法的变种,使用2个cnt,可以保证1/3的必在其中
            // num1 和num2肯定是不同的两个数
            for (int v:nums) {
                if (v==num1) {
                    cnt1++;
                } else if (v==num2) {
                    cnt2++;
                } else if (cnt1==0) {
                    num1 = v;cnt1=1;
                } else if (cnt2==0) {
                    num2 = v;cnt2=1;
                } else {
                    cnt1--;cnt2--;
                }
            }
            cnt1 = 0, cnt2 = 0;
            for(auto val: nums)
                if(val == num1) cnt1++;
                else if(val == num2) cnt2++;
            vector<int> ans;
            if(cnt1 > len/3.0) ans.push_back(num1);
            if(cnt2 > len/3.0) ans.push_back(num2);
            return ans;
        }
    };
}