package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

//[1,3],[2]->2
//[1,2],[3,4] -> (2+3)/2 = 2.5
// exp O(log(m+n))


// 这个还是画图比较直观
// A                                              |  B
// A[0],[1]....[m1-1] | A[m1],[m1+1]....[n1-1]    | B[0],[1]...[m2-1],[m2]... [n2-1]
// 取出[0]..[m-1] (m1); B取出 [0]..[m2-1] 合计m2个
// 要取出的数字为 m1+m2 = k
// [0],[1],...[k-1],[k],....[n1+n2-1]
// even 偶数的话, 要取出2个数，例如(2+4)，要取出k=3,4，即num[2],[3]这两个数，所以k=(n1+n2)/2
// odd 奇数, 只需要取出1个数，例如(2+7), 那么要取出第5个数,即k=5, (n1+n2+1)/2=k,例如(2+7+1)/2=5,要取出5个数，[0]...[k-1],要求num[k-1]
// 可以 int k = (len1+len2)%2==1?(len1+len2+1)/2:(len1+len2)/2;
// 但实际上可以 k = (n1+n2+1)/2覆盖2种情况

public class Lc0004_median2sortedarr extends BaseSolution {
    class Solution {
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            int len1 = nums1.length;
            int len2 = nums2.length;
            if (len1 > len2)
                return findMedianSortedArrays(nums2, nums1);

            int low = 0, high = len1;
            double ret = 0;

            // m1 表示nums1中需要取出的数量
            // m2 表示nums2中需要取出的数量
            // k 表示合计需要取出的左边的数字
            //int k = (len1+len2)%2==1?(len1+len2+1)/2:(len1+len2)/2;
            int k = (len1+len2+1)/2;

            while (low < high) {
                int m1 = (high + low)/2;    // 取出m1
                int m2 = k - m1;            // 所以从nums2中取出剩余的k-m1;
                // 如果nums1中未取出的那个数[m1] 小于 num2中被取出的最大的那个数[m2-1],意味着
                // 需要从nums1中取更多的数,因为m1取出，所以下限从m+1起算
                if (nums1[m1] < nums2[m2-1]) {
                    low = m1+1;
                } else {
                    // 如果nums1中未取出的那个数[m1] 大于等于 num2中被取出的最大的那个数[m2-1],意味着
                    // 可以少取一点数,因为退出条件是<high,所以上限改成m1
                    high = m1;
                }
            }

            // 退出时m1=low, 例如, l=4,h=5,l->4+1=5，取出5个元素
            // 或者high = 4,low = 4,退出，取4个元素
            // 退出时的m1 取值为low(low可能==high，即最多取光),或者low==high==0,
            // 这是一个非常漂亮的2分法对多个array进行同时排序的算法
            int m1 = low;
            int m2 = k- low;
            int c1 = max(
                    m1<=0?Integer.MIN_VALUE:nums1[m1-1],
                    m2<=0?Integer.MIN_VALUE:nums2[m2-1]);
            if ((len1+len2)%2==1) {
                return c1;
            }

            int c2 = min(
                    m1>=len1?Integer.MAX_VALUE:nums1[m1],
                    m2>=len2?Integer.MAX_VALUE:nums2[m2]);
            return (c1+c2)/2.0;

        }

    }
}
