package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import static java.lang.Math.min;

//Input: n = 10
//Output: 12
//Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// 首先判断ugly的做法就是逐个%2,3,5，但是计算量很大
//使用一个数组保存每一个ugly数字
//假设用P2,P3,P5记下3个丑数的位置，分别*2,3,5，取出最小的，而且大于目前最后一个丑数的，作为下一个丑数
public class Lc0264_ugly2 extends BaseSolution {
    class Solution {
        public int nthUglyNumber(int n) {
            int arr[]=new int[n];
            arr[0]=1;
            int i2=0,i3=0,i5=0;
            int next=1;
            while (next<n) {
                arr[next] = min(min(arr[i2]*2,arr[i3]*3),arr[i5]*5);
                while (arr[i2]*2 <=arr[next]) i2++;
                while (arr[i3]*3 <=arr[next]) i3++;
                while (arr[i5]*5 <=arr[next]) i5++;
                next++;
            }
            return arr[n-1];
        }
    }

}


/*
using namespace std;

namespace {
    class Solution {
    public:
        int getUgly(int index) {
            vector<int> arr(index);
            if (index<=0) return 0;
            arr[0]=1;
            int *u2=&arr[0],*u3=&arr[0],*u5=&arr[0];
            int next=1;
            while (next < index) {
                arr[next]=std::min({*u2*2,*u3*3,*u5*5});
                while (*u2*2<=arr[next])
                    u2++;
                while (*u3*3<=arr[next])
                    u3++;
                while (*u5*5<=arr[next])
                    u5++;
                next++;
            }
            return arr[index-1];
        }
    };
}

 */