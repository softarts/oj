//
// Created by rui zhou on 2019-09-05.
//

/*
 * https://leetcode.com/problems/subarray-sum-equals-k/
 * Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,0000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 */
#include <codech/codech_def.h>

using namespace std;
using namespace CODECH;

namespace {
    //brute force
    class Solution0 {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int ans = 0;
            for (size_t i=0;i < nums.size();i++) {
                int sum = 0;
                for (size_t j=i;j < nums.size();j++) {
                    sum+=nums[j];
                    if (sum==k)
                        ans++;
                }
            }
            return ans;
        }
    };
    //
    class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int ans = 0;
            unordered_map<int,int> m{{0,1}};
            int sum = 0;
            for (size_t i=0;i < nums.size();i++) {
                sum += nums[i];
                ans += m[sum-k];
                m[sum]++;
            }
            return ans;
        }
    };
}

DEFINE_CODE_TEST(560_subarray_sum_equal_k)
{
    Solution obj;
    {
        vector<int> nums {1,1,1};
        VERIFY_CASE(obj.subarraySum(nums,2),2);

    }
}