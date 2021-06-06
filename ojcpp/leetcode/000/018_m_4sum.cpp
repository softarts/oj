//
// Created by rui.zhou on 2/19/2019.
//

/*
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

class Solution {
public:
    vector<int> data;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return ksum(nums,target,4);
    }
    vector<vector<int>> ksum(vector<int>& nums, int target, int k) {
        sort(nums.begin(),nums.end());
        data=nums;
        if (data.size()<k)
            return vector<vector<int>>();
        else
            return doKsum(0,data.size()-1,target, k);
    }

    vector<vector<int>> doKsum(int start, int end, int target, int k) {
        vector<vector<int>> ret;
        if (k==2) {
            while (start<end) {
                if (data[start]+data[end]==target) {
                    ret.push_back(vector<int>{data[start],data[end]});
                    while (start<end && data[start]==data[start+1]) start++;
                    while (start<end && data[end]==data[end-1]) end--;
                    start++;end--;
                } else if (data[start]+data[end]<target) {
                    start++;
                } else {
                    end--;
                }
            }
            return ret;
        } else {
            for (int i=start;i<=end;i++) {
                if (i!=start && i>0 && data[i]==data[i-1]) {
                    continue; //这里处理有瑕疵,补上i!=start，对于每一轮的子k-1sum,
                    // 不需要考虑与ksum的上一个元素是否一致
                }
                int v=data[i];
                auto subList = doKsum(i+1, end, target-v, k-1);
                for (auto &vec : subList) {
                    vec.insert(vec.begin(), v);
                }
                ret.insert(ret.end(),subList.begin(), subList.end());
            }
        }
        return ret;
    }
};

DEFINE_CODE_TEST(018_4sum)
{
    Solution obj;
    {
        vector<int> nums{1, 0, -1, 0, -2, 2};
        VERIFY_CASE(PRINT_VVEC(obj.fourSum(nums,0)),"-2 -1 1 2 -2 0 0 2 -1 0 0 1 ");
    }
    {
        vector<int> nums{};
        VERIFY_CASE(PRINT_VVEC(obj.fourSum(nums,0)),"");
    }

    {
        vector<int> nums{-1,-1,-1,-1,1,1,1,1,0,0,0,0};
        VERIFY_CASE(PRINT_VVEC(obj.fourSum(nums,0)),"-1 -1 1 1 -1 0 0 1 0 0 0 0 ");
    }
}
