//
// Created by rui zhou on 2019-11-17.
//
// 0,1,2,3...n-1,共 n个数字，从1开始计数，第m个数字出列，然后接着重新以1开始计数,问最后一个剩下的数字是？
// 思路1
// f(1) = 0,表示最后剩下的数字index=0;
// 那么当f(2)的时候，剩下的数字的idx将是: f(1)+m%n(因为m-1被移除了)
// f(3),该数字的idx = f(2)
// 倒退比较难

// 思路2
// f(n,m),去除第m个数字,剩下 0,1,2,...m-2,(m-1), m,m+1...n-1
// f(n-1,m),,对剩余数字重新编号(0)n-m,(1)n-m+1,...(m-2)n-2, 0,1,...n-1-m, 括号内为上一轮的编号
// 得到关系, f(n,m) =

// f(n,m),去除第m个数字,剩下
/*
N           -----   N-1         --- N-2
0           -----   n-m%n
1           -----   n-m%n+1
2           -----   ...
...
m%n-2       -----   n-2
(m%n-1)     -----
m%n         -----   0
m%n+1       -----   1
...         -----   ...
n-1         -----   n-1-m%n

===>
 可以得到
x = (x-m)%n
逆映射 为
 f(1) = 0
 f(n) = (f(n-1)+m)%n

*/
// f(n-1,m),,对剩余数字重新编号(0)n-m%n,(1)n-m%n+1,...(m-2)n-2, (m%n)0,1,...n-1-m%n, 括号内为上一轮的编号
// f(n,m) = f(n-1,m)%n+m%n -> (f(n-1,m)+m)%n
// f(1) = 0

#include <codech/codech_def.h>
using namespace std;

using namespace std;
namespace {
    class Solution {
    public:
        int lastnumber(int n, int m) {
            int ans;
            int last = 0;
            for (int i = 2; i <= n; i++) {
                last = (last + m) % i;
            }
            return last;
        }
    };
}


DEFINE_CODE_TEST(045_joseph_circle)
{
    Solution obj;
    {
        VERIFY_CASE(obj.lastnumber(5,3),3);
    }
}