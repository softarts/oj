//
// Created by Rui Zhou on 29/3/18.
//

/*
 * https://leetcode.com/problems/combination-sum/description/
 * Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
思路， 采用DFS，由于不限制每个数的使用次数，因此先排序，然后可以一直取某个数，
直到超过target时退出。
 //TODO DP?
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace std;
using namespace CODECH;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        dfs(candidates, res, comb, target, 0);
        return res;
    }

    void dfs(vector<int>& arr, vector<vector<int>> &res, vector<int> &comb, int target, int begin) {
        if (!target) {
            res.push_back(comb);
            return;
        }
        for (int i=begin; i < arr.size() && target >= arr[i];i++) {
            comb.push_back(arr[i]);
            dfs(arr, res, comb,target-arr[i], i);
            comb.pop_back();
        }
    }
};


//void printvv(vector<vector<int>> &&vec) {
//    for (auto &r : vec) {
//        for (auto p: r) {
//            cout << p << " ";
//        }
//    }
//}

DEFINE_CODE_TEST(039_combinationsum)
{
    Solution obj;
    {
        vector<int> nums{2,3,6,7};
        VERIFY_CASE(PRINT_VVEC(obj.combinationSum(nums, 7)),"2 2 3 7");
    }
}