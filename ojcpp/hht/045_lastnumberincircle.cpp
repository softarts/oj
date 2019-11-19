//
// Created by rui zhou on 2019-11-17.
//
// 0,1,2,3...n-1,共 n个数字，从1开始计数，第m个数字出列，然后接着重新以1开始计数,问最后一个剩下的数字是？
// 思路1
// f(1) = 0,表示最后剩下的数字index=0;
// 那么当f(2)的时候，剩下的数字的idx将是: f(1)+m%n(因为m-1被移除了)
// f(3),该数字的idx = f(2)
// 倒退比较难
#include <codech/codech_def.h>
using namespace std;

using namespace std;
namespace {
    class Solution {
    public:
        int lastnumbery(vector<int> &nums, int idx) {
            int ans;

            return ans;
        }
    };
