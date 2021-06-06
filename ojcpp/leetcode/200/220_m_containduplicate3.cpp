/*
Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

2021-05-16
如果要2个loop的话，N^2
如何判断一个数周围k个数以内有差异小于t的数存在
sort整个list,并且带上序号，然后从小开始比较
*/
#include <codech/codech_def.h>
using namespace std;
namespace {
    class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
    }
};
}