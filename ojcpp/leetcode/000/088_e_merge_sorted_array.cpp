//
// Created by rui.zhou on 3/17/2019.
//

/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
难点在于n要合并到nums1中,从头部开始的话会覆盖，因此从尾部开始，关键！！！

Output: [1,2,2,3,5,6]
 idx1 = 0
idx2 = 0
offset = 0

if m != len(nums1):
    del nums1[-(len(nums1) - m):]
while idx1 < m and idx2 < n:
    v1 = nums1[offset+idx1]
    v2 = nums2[idx2]
    if v2 <= v1:
        nums1.insert(offset+idx1, v2)
        offset += 1
        idx2 += 1
    else:
        idx1 += 1
if idx1 == m:
    nums1.extend(nums2[idx2:n])
 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int n1 = nums1.size() - nums2.size() -1, n2 = nums2.size()-1, k = nums1.size() - 1;

            while(n1 >= 0 && n2 >= 0){
                if(nums1[n1] < nums2[n2]) nums1[k--] = nums2[n2--];
                else nums1[k--] = nums1[n1--];
            }
            while(n1 >= 0) nums1[k--] = nums1[n1--];
            while(n2 >= 0) nums1[k--] = nums2[n2--];
        }
    };
}