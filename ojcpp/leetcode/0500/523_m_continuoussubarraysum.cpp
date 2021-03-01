//
// Created by Rui Zhou on 30/3/18.
//

/*
 * https://leetcode.com/problems/continuous-subarray-sum/
 * Given a list of non-negative numbers and a target integer k,
 * write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k,
 * that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,0000.

You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

重复数字？
找出连续数组的和是K的倍数，yitu 面试题
 */


// hello

// 10级台阶， 有一个人，需要从台阶底部，走上顶部。
// 每次可以走1级，也可以走2级，请问他走上10级台阶有多少种不同的走法？

// count, 输入 int 类型数组， 假设每个数都是正整数。
// nums[i] <= 1000, size(nums) <= 10000
// return int, 表示 多少个子串，序列和，是 7的倍数。
// 3, 6, 7, 1, 2, 7
// [7], [6, 7, 1], [7], return 3, 连续的

#include <codech/codech_def.h>

using namespace std;
namespace {
    class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) {
            /*那就是，若数字a和b分别除以数字c，若得到的余数相同，那么(a-b)必定能够整除c*/
            int n = nums.size(), sum = 0;
            unordered_map<int, int> m{{0,-1}}; // 表示map[0]=-1，作为一个起始位
            for (int i = 0; i < n; ++i) {
                sum += nums[i];
                int t = (k == 0) ? sum : (sum % k);  //为余数
                if (m.count(t)) {
                    if (i - m[t] > 1) return true; //表示在前一个数之后,但是i=0不行，因为>1不成立
                } else m[t] = i;  //记下索引
            }
            return false;
        }
    };
}
    /*
    bool checkSubarraySum0(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0;i < nums.size();i++) {
            int sum = nums[i];
            if (sum>=k && (sum  % k ==0))
                count++;

            for (int j = i+1;j<nums.size();j++) {
                sum += nums[j];
                if (sum >= k && (sum % k ==0)) {
                    count++;
                }
            }
        }
        return count;
    }

    bool checkSubarraySum1(vector<int>& nums, int k) {
        if (k==1) {
            if (nums.size()>1)
                return true;
            else
                return false;
        }
        for (int i = 0;i < nums.size();i++) {
            int sum = nums[i];
            for (int j = i+1;j<nums.size();j++) {
                sum += nums[j];
                if (k==0) {
                  if (sum==0)
                      return true;
                  else
                      break;
                }  else {
                    if (sum >= k && (sum % k ==0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    */



DEFINE_CODE_TEST(523_continuous_subarray)
{
    Solution obj;
    {
        vector<int> nums{23,2,6,4,7};
        VERIFY_CASE(obj.checkSubarraySum(nums,6),true);
    }
    {
        vector<int> nums{23,2,6,4,7};
        VERIFY_CASE(obj.checkSubarraySum(nums,0),false);
    }
    {
        vector<int> nums{0};
        VERIFY_CASE(obj.checkSubarraySum(nums,6),false);
    }

    {
        vector<int> nums{0,0};
        VERIFY_CASE(obj.checkSubarraySum(nums,6),true);
    }
    {
        vector<int> nums{0,0};
        VERIFY_CASE(obj.checkSubarraySum(nums,0),true);
    }

    {
        vector<int> nums{23,0,0};
        VERIFY_CASE(obj.checkSubarraySum(nums,6),true);
    }
}
