//
// Created by rui.zhou on 5/6/2019.
//

// 从1到整数N中 1出现的次数
// n=10,出现1，10 两次
// n=100,出现1,10,11,12...19,21,31,41,...91, 9+9=18 次
//LC 233 hard
// N=12-> 1,10,11,12 = 5次
#include <codech/codech_def.h>
using namespace std;

// 一般做法
namespace {
    class Solution {
    public:
        int numberof1(int n) {
            int number1(int x) {
                int count =0;
                while (x) {
                    count+= (x%10==1);
                }
                return count;
            }
            for (int i=1,;i<=n;i++) {

            }
        }
    };
}