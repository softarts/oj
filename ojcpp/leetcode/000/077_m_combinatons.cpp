//
// Created by rui zhou on 06/03/19.
//

/*
 * https://leetcode.com/problems/combinations/
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace lc077 {
    class Solution {
    public:
        void dfs(vector<vector<int>> &ret,vector<int> &comb,vector<int>&nums,int pos, int k) {
            if (comb.size()==k) {
                ret.emplace_back(comb);
                return;
            }
            for (int i=pos;i<nums.size();i++) {
                comb.emplace_back(nums[i]);
                dfs(ret,comb,nums,i+1,k);
                comb.pop_back();
            }
        }
        // return rvalue
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> ret;
            vector<int> comb;
            vector<int> nums;
            for (int i=1;i<=n;i++) {
                nums.emplace_back(i);
            }
            dfs(ret,comb,nums,0,k);
            return ret;
        }
    };
}


DEFINE_CODE_TEST(077_combinator)
{
    lc077::Solution obj;
    {
        //VERIFY_CASE(PRINT_VVEC(obj.combine(4,2)),"1 2 1 3 1 4 2 3 2 4 3 4");

        vector<vector<int>> exp{{2,4},{3,4},{2,3},{1,2},{1,3},{1,4}};
        VERIFY_CASE(VERIFY_VVECINT(obj.combine(4, 2), exp),true);
    }
}