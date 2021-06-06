//
// Created by Rui Zhou on 2/3/18.
//

/*
 * https://leetcode.com/problems/subsets/description/
 * Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

 1.找出所有的组合，一种办法是用组合，先建立一个空的集合，然后每次循环都往集合里放东西
//    这种方法是一种组合的方式//
//    1.最外层循环逐一从 nums 数组中取出每个元素 num
//    2.内层循环从原来的结果集中取出每个中间结果集，并向每个中间结果集中添加该 num 元素

 2.backtracking
//    这种题目都是使用这个套路，就是用一个循环去枚举当前所有情况，然后把元素加入，递归，再把元素移除
//            按照这个套路来做，可以解决backTracking的问题
//
//    list.add(nums[i]); // 第三步 元素加入临时集合
//    backTracking(res, list, nums, i + 1); // 第四步 回溯
//    list.remove(list.size() - 1); // 第五步 元素从临时集合移除
//


 find all subset, iterate ()->(),(1)->(),(1),(2),(1,2)
 */

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

namespace subset {
    class Solution {
    public:
        //还是组合的方式
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res{{}};
            for (auto num : nums) {
                vector<vector<int>> tmp;
                for (auto &v : res) {
                    v.push_back(num);
                    tmp.push_back(v);
                }
                res.insert(res.end(), tmp.begin(), tmp.end());
            }
            return res;
        }
    };


    // 这是什么套路? - 第一种，组合的套路
    class Solution0 {
    public:
        vector<vector<int>> ret;
        vector<vector<int>> subsets(vector<int> &nums) {
            vector<vector<int>> subs(1, vector<int>());
            for (int i = 0; i < nums.size(); i++) {  //枚举所有情况
                int n = subs.size();
                for (int j = 0; j < n; j++) {
                    subs.push_back(subs[j]);
                    subs.back().push_back(nums[i]);
                }
            }
            return subs;
        }
    };

    //可以选当前这个，也可以不选，然后进入下一层
    class Solution1 {
    public:
        vector<vector<int>> ret;
        void findsub(vector<int>& nums,vector<int> &comb, int start,int end) {
            if (start==end) {
                ret.emplace_back(comb);
                return;
            }
            comb.emplace_back(nums[start]);
            findsub(nums,comb,start+1,end);
            comb.pop_back();
            //or skip
            findsub(nums,comb,start+1,end);
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> comb;
            findsub(nums,comb,0,nums.size());
            return ret;
        }
    };

    // backtracking标准套路
    class Solution2 {
    public:
        vector<vector<int>> ret;
        void dfs(vector<int>& nums,vector<int> &comb, int start) {
            ret.emplace_back(comb); //每次都放入ret，因为是subset
            for (int i=start;i<nums.size();i++) {
                comb.emplace_back(nums[i]);
                dfs(nums,comb,i+1);
                comb.pop_back();
            }
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> comb;
            dfs(nums,comb,0);
            return ret;
        }
    };

}

//void printvec(vector<vector<int>> &&nums) {
//    for_each(nums.begin(),nums.end(),[](auto v) {
//        cout << "[";
//        for (auto e : v) {
//            cout << e << ",";
//        }
//        cout << "],";
//    });
//}


DEFINE_CODE_TEST(078_subset)
{
    subset::Solution2 obj;
    {
        vector<int> nums{1,2,3};
        VERIFY_CASE(PRINT_VVEC(obj.subsets(nums)),"1 2 3 1 2 1 3 1 2 3 2 3");
    }
}