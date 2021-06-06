//
// Created by rui.zhou on 3/8/2019.
//

/*
 * https://leetcode.com/problems/subsets-ii/
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
namespace lc090 {
    // backtracking 套路，选取非重复数字时注意条件
    // 由于可能有duplicate,必须先排序
    // 先push, dfs,在pop
    class Solution {
    public:
        void dfs(vector<vector<int>> &ret,vector<int> &comb, int pos,vector<int>& nums ) {
            ret.emplace_back(comb);
            for (int i=pos;i<nums.size();i++) {
                if (i!=pos && nums[i]==nums[i-1])  //注意不要duplicate
                    continue;
                comb.emplace_back(nums[i]);
                dfs(ret,comb,i+1,nums);//注意是i+1
                comb.pop_back();
            }
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ret;
            vector<int> comb;
            sort(nums.begin(),nums.end());
            dfs(ret, comb, 0,nums);
            return ret;
        }
    };
}

DEFINE_CODE_TEST(090_subsets2)
{
    lc090::Solution obj;
    {
        vector<int> nums = { 1,2,2};
        vector<vector<int>> exp={{2},{1},{1,2,2},{2,2},{1,2},{}};
        VERIFY_CASE(VERIFY_VV(obj.subsetsWithDup(nums),exp),true);
    }

}