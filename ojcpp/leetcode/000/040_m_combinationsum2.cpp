//
// Created by rui.zhou on 2/23/2019.
//

/*
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
和040区别在于每个数字只能用一次
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        dfs(res, comb, candidates, target,0);
        return res;
    }

    void dfs(vector<vector<int>> &res,vector<int> &comb,vector<int>& nums,int target, int begin) {
        if (target==0) {
            res.emplace_back(comb);
            return;
        }

        for (int i=begin;i<nums.size()&&target>=nums[i];i++) {
            if (i!=begin && nums[i]==nums[i-1]) {  //条件，本次循环中不允许重复使用
                continue;
            }
            comb.emplace_back(nums[i]);
            dfs(res,comb,nums,target-nums[i],i+1);
            comb.pop_back();

        }
    }
};

DEFINE_CODE_TEST(040_combinationsum2)
{
    Solution obj;
    {
        vector<int> nums{10,1,2,7,6,1,5};
        VERIFY_CASE(PRINT_VVEC(obj.combinationSum2(nums, 8)),"1 1 6 1 2 5 1 7 2 6");
    }
    {
        vector<int> nums{2,5,2,1,2};
        VERIFY_CASE(PRINT_VVEC(obj.combinationSum2(nums, 5)),"1 2 2 5");
    }
    {
        vector<int> nums{};
        VERIFY_CASE(PRINT_VVEC(obj.combinationSum2(nums, 5)),"");
    }
    {
        vector<int> nums{5};
        VERIFY_CASE(PRINT_VVEC(obj.combinationSum2(nums, 5)),"5");
    }
    {
        vector<int> nums{5,5,5,5,5};
        VERIFY_CASE(PRINT_VVEC(obj.combinationSum2(nums, 5)),"5");
    }
}