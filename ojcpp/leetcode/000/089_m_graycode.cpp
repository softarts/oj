//
// Created by rui.zhou on 3/7/2019.
//

/*
 * The gray code is a binary numeral system where two successive values differ in
 * only one bit.
Given a non-negative integer n representing the total number of bits in the code,
 print the sequence of gray code. A gray code sequence must begin with 0.

Example 1:

Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1
Example 2:

Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0].
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace lc089 {
    // 方法完全不对，无法保证只变动一个bit，需要找规律。
//    class Solution {
//    public:
//        vector<vector<int>> ret;
//        void dfs(int pos, vector<int> &nums) {
//            for (int i=pos;i<nums.size();i++) {
//                //int tmp=nums[i];
//                nums[i]=nums[i]^1;
//                ret.emplace_back(nums);
//                dfs(i+1,nums);
//                //nums[i]=tmp;
//            }
//        }
//        vector<int> grayCode(int n) {
//            ret.clear();
//            vector<int> nums;
//            for (int i=0;i<n;i++) {
//                nums.emplace_back(0);
//            }
//            ret.emplace_back(nums);
//            dfs(0,nums);
//
//            vector<int> ret2;
//            for (auto &vec : ret) {
//                int k=0;
//                for (int i=0;i<vec.size();i++) {
//                    k=k*2+vec[i];
//                }
//                ret2.emplace_back(k);
//            }
//            return ret2;
//        }
//    };

    // 思路， 00 01 | 11 10， 看出每个循环里对之前的数字，逆序+ 1(0循环次数），第一次是1，10，100。。
    class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> ret{0};
            for (int i=0;i<n;i++) {
                int shift=1<<i;
                int sz=ret.size();
                for (int j=sz-1;j>=0;j--) {
                    ret.emplace_back(ret[j]+shift);
                }
            }
            return ret;
        }
    };

}


DEFINE_CODE_TEST(089_graycode)
{
    lc089::Solution obj;
    {
        // good for left->right
//        VERIFY_CASE(PRINT_VEC(obj.grayCode(2)),"0 2 3 1");
//        VERIFY_CASE(PRINT_VEC(obj.grayCode(0)),"0");
        VERIFY_CASE(PRINT_VEC(obj.grayCode(2)),"0 1 3 2");
        VERIFY_CASE(PRINT_VEC(obj.grayCode(0)),"0");
        VERIFY_CASE(PRINT_VEC(obj.grayCode(3)),"0 1 3 2 6 7 5 4");

        //[0,4,6,7,5,2,3,1]->wrong
        //[0,1,3,2,6,7,5,4]
    }
}