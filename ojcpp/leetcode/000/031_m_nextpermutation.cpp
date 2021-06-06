//
// Created by rui.zhou on 2/20/2019.
//

/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 next permutation实现
 从右往左，找到第一个降序的位置(v[i]<v[i+1]),左边比右边小的数字,例如1,2,3中的2
 然后从右往左到i位置，找到第一个大于v[i]的数字，swap之,1,2,3 中的3,交换=>1,3,2
 再把i+1到end位置逆序，即左到右从小到达排列(原来是从大到小) 从2之后的数字逆序
此时返回
 如果均找不到，表明从左到右已经完全降序排列，需要reverse

 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }

    template<class BidDirIt>
    bool next_permutation(BidDirIt first, BidDirIt last) {
        if (first==last) return false;
        BidDirIt i = last;
        if (first==--i) return false; // only 1 element return false

        while (true) {
            BidDirIt i1=i;
            if (*(--i)<*i1) {  // find first element < right of it.
                BidDirIt i2=last;
                while (*i>=*--i2);  // at least [i+1]>=[i]
                swap(*i,*i2);  // found i2
                reverse(i1,last);
                return true;
            }
            if (i==first) {
                reverse(first, last);
                return false;
            }
        }
    }
};
DEFINE_CODE_TEST(031_nextpermutation)
{
    Solution obj;
    {
        vector<int> nums{1,2,3};
        obj.nextPermutation(nums);
        VERIFY_CASE(PRINT_VEC(std::move(nums)),"1 3 2");
    }
    {
        vector<int> nums{1,5,1};
        obj.nextPermutation(nums);
        VERIFY_CASE(PRINT_VEC(std::move(nums)),"5 1 1");
    }
}
