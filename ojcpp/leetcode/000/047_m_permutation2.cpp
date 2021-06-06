//
// Created by rui.zhou on 3/5/2019.
//

/*
 * https://leetcode.com/problems/permutations-ii/
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;


//采用046的做法可能不妥，不和相同的数字交换，直觉上应该是不对的，2211,有可能2121的时候,1和2交换，又变成2211了。
//不使用046的相互交换的做法，而是使用选取组合的做法，类似039
//组合的基本套路是?
//class Solution {
//public:
//    void dfs(int start, int end, vector<int> comb,vector<vector<int>> &ret) {
//        if (start==end-1) {
//            ret.emplace_back(comb);
//            cout<<PRINT_VEC(std::move(comb))<<endl;
//        }
//        unordered_set<int> visited;
//        for (int i=start;i<end;i++) {
//            if (visited.count(comb[i])==0) {
//                swap(comb[start],comb[i]);
//                visited.emplace(comb[i]);
//                dfs(start+1,end,comb, ret);
//            }
//
//
//        }
//    }
//
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        vector<vector<int>> ret;
//        dfs(0,nums.size(),nums, ret);
//        return ret;
//    }
//};
namespace permutation2 {
    class Solution {
    public:

        void dfs(vector<vector<int>> &ret, vector<int> &comb,vector<int> &nums, vector<bool>&visited) {
            if (comb.size()==nums.size()) {
                ret.emplace_back(comb);
                return;
            }
            for (int i=0;i<nums.size();i++) {
                if (i!=0 && nums[i]==nums[i-1] && visited[i-1]==false) {
                    //条件，本次循环中不允许重复使用
                    // 考虑 1 1 2, 当i=0时，选用了1,i=1时，不应该再用第二个1，此时visited[i-1]=false
                    //在backtracking中，visited[i-1]=true,已被选用
                    continue;
                }
                if (!visited[i]) {
                    visited[i]=true;
                    comb.emplace_back(nums[i]);
                    dfs(ret,comb,nums,visited);
                    visited[i]=false;
                    comb.pop_back();
                }
            }
        }
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> ret;
            vector<bool> visited(nums.size(),false);
            vector<int> comb;
            sort(nums.begin(),nums.end());
            dfs(ret, comb,nums,visited);
            return ret;
        }
    };
}


// 排列问题且唯一问题，可以用hashmap，从里面挑数字
DEFINE_CODE_TEST(047_permutation2)
{
    permutation2::Solution obj;
    {
        vector<int> nums{2,2,1,1};
        VERIFY_CASE(PRINT_VVEC(obj.permuteUnique(nums)),"1 1 2 2 1 2 1 2 1 2 2 1 2 1 1 2 2 1 2 1 2 2 1 1");
    }
    {
        vector<int> nums{3,3,0,3};
        VERIFY_CASE(PRINT_VVEC(obj.permuteUnique(nums)),"0 3 3 3 3 0 3 3 3 3 0 3 3 3 3 0");
    }
    {
        vector<int> nums{1,1,2};
        VERIFY_CASE(PRINT_VVEC(obj.permuteUnique(nums)),"1 1 2 1 2 1 2 1 1");
    }
    {
        vector<int> nums{1,1,1};
        VERIFY_CASE(PRINT_VVEC(obj.permuteUnique(nums)),"1 1 1");
    }

    {
        vector<int> nums{1,1,1,2};
        VERIFY_CASE(PRINT_VVEC(obj.permuteUnique(nums)),"1 1 1 2 1 1 2 1 1 2 1 1 2 1 1 1");
    }




}