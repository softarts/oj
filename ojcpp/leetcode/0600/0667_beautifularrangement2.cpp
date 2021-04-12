/*
Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement:
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
Example 2:
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
*/
// 思路，构造一个list, 使得|a1-a2|,|a2-a3|...存在k个不同的数
// 11:30PM
// 12:00 想到一种循环交换的方法，但是实现起来较繁琐
// 考虑1,2,3,4,5,6,7,依次插入1,7,2,6,一个正序，一个倒序，当得到所有的数字后，在全部正序插入
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        vector<int> constructArray(int n, int k) {
            vector<int> res;
            int l = 1, r = n;
            while (l<=r) {
                if (k>1) {
                    // 注意=1起
                    k%2==1?res.push_back(l++):res.push(r--);
                    k--;
                } else {
                    res.push_back(l++);
                }
            }
            return res;
        }
    };
}