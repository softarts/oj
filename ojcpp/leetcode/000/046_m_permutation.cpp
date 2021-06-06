//
// Created by rui.zhou on 3/5/2019.
//
/*
 * Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace permutation {
    class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>> ret{nums};
            while (next_permutation(nums.begin(),nums.end())) {
                ret.emplace_back(nums);
            }
            return ret;
        }
    };

    // 1.使用next_permutation
    // 2. HHT offer p172, 递归的做法,把第一个字符和后面所有字符交换(包括自身)，然后再递归(start++)求后面的部分的和其第一个字符的交换
    // 当start到达尾部的时候退出递归，添加结果
    // 1 2 3->1 2 3 -> 1 2 3
    //          |-> 1 3 2 --> 1 3 2
    //
    class Solution1 {
    public:
        void dfs(int start,int end, vector<int> comb,vector<vector<int>> &ret) {
            if (start==end-1) {
                ret.emplace_back(comb);
                cout<<PRINT_VEC(std::move(comb))<<endl;
            }

            for (int i=start;i<end;i++) {
                swap(comb[start],comb[i]);
                dfs(start+1,end,comb, ret);
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ret;
            dfs(0,nums.size(),nums, ret);
            return ret;
        }
    };

}


DEFINE_CODE_TEST(046_permutation)
{
    permutation::Solution1 obj;
    {
        vector<int> nums{1,2,3};
        VERIFY_CASE(PRINT_VVEC(obj.permute(nums)),"1 2 3 1 3 2 2 1 3 2 3 1 3 1 2 3 2 1");
    }
    {
        vector<int> nums{0,-1,1};
        VERIFY_CASE(PRINT_VVEC(obj.permute(nums)),"0 -1 1 0 1 -1 -1 0 1 -1 1 0 1 0 -1 1 -1 0");
    }
}
