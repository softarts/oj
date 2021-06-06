//
// Created by rui zhou on 18/02/19.
//

/*
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

 一种是基于twosum来做，对于每一个element，都去检查剩余的list是否有符合要求的twosum,使用hashmap
另一种是先sort，然后再one pass,仍然是O(N^2)
 */

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int len=nums.size();
        //cout <<nums.size()-2<<endl;
        // a trap if size()=0
        for (int i=0;i<len-2;i++) {
            // 注意排除 连续相等的element, -1,-1,-1,2,2,2,2,
            // 或者使用set
            if (i>0 && nums[i]==nums[i-1])
                continue;
            int l=i+1;
            int r=len-1;
            while (l<r) {
                int sum = nums[i]+nums[l]+nums[r];
                if (sum>0) { // 表明要移动右侧
                    r--;
                } else if(sum<0) {
                    l++;  //移动左侧
                } else { // equal
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while (l< len-1 &&nums[l]==nums[l+1]) l++;
                    while (r>0 && nums[r]==nums[r-1]) r--;
                    l++;r--;
                }
            }
        }
        return res;

    }
};

DEFINE_CODE_TEST(015_3sum)
{
    Solution obj;
    {
        vector<int> nums{};
        VERIFY_CASE(PRINT_VVEC(obj.threeSum(nums)),"");
    }
    {
        vector<int> nums{-1, 0, 1, 2, -1, -4};
        VERIFY_CASE(PRINT_VVEC(obj.threeSum(nums)),"-1 -1 2 -1 0 1 ");
    }


}
