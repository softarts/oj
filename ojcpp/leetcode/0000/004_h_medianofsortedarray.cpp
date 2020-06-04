//
// Created by rui.zhou on 2/10/2019.
//

/*https://leetcode.com/problems/median-of-two-sorted-arrays/
 *There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
寻找中位数的值.(合并数组)
对2个数组，取k/2位置的值比较，将小的那个数组的前k/2的范围去掉，大的数组的后k/2范围去掉
最后退出条件为
http://www.cnblogs.com/grandyang/p/4465932.html

 */
#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    // O(m+n), 类似merge sort的做法，合并两个数组
    // 这个没优化
    double findMedianSortedArrays0(vector<int>& nums1, vector<int>& nums2) {
        int64_t max = std::numeric_limits<int64_t>::max();
        int m=nums1.size()+nums2.size();
        int i = 0, j = 0, f = 0, k, kk;
        int end = m/2;   //m为偶数，找到m/2和m/2-1，m为奇数，找到m/2
        while(f<=end){
            kk = k;  //用来记录m/2-1
            int64_t n1 = i<nums1.size()?nums1[i]:max;
            int64_t n2 = j<nums2.size()?nums2[j]:max;
            if (n1<=n2) {
                k=nums1[i++];
            } else {
                k=nums2[j++];
            }
            f++;
        }
        float ans = m%2==0?( k+kk)/2.0:k;
        return ans;
    }

    // 迭代形式的二分法
    //https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/very-concise-ologminmn-iterative-solution-with-detailed-explanation
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        return 0.;
    }

    //https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/231213/Java-Solution-99-Percentile
    //https://www.youtube.com/watch?v=LPFhl65R7ww
    // 对两个数组进行切分，保证左右两侧加起来的个数相等
    // 太精巧了，需要细细体会

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m>n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low=0,high=m;
        double result = 0;

        while (low<=high) {
            int partx = (high+low)/2;     // x分成2半，有几个
            // partx+party = (m+n+1)/2， 总数/2 - partx,表示要给x 补上的数量
            // 为何是 m+n+1?
            int party = (m+n+1)/2-partx;

            // 分别得出两个区间
            int leftxmax = (partx>0?nums1[partx-1]:INT_MIN);
            int rightxmin = (partx<m?nums1[partx]:INT_MAX);

            int leftymax = (party>0?nums2[party-1]:INT_MIN);
            int rightymin = (party<n?nums2[party]:INT_MAX);

            // 退出条件
            if (leftxmax <= rightymin && leftymax <= rightxmin) {
                if ((n+m)%2==0) {
                    result = (double)(max(leftxmax,leftymax) + min(rightxmin,rightymin))/2.0;
                } else {
                    result = (double)max(leftxmax,leftymax);
                }
                break;
            } else if (leftymax>rightxmin){  //
                low = partx+1;
            } else {
                high = partx-1;
            }
        }
        return result;
    }
};

DEFINE_CODE_TEST(004_mediansortedarray)
{
    Solution obj;
    {
        vector<int> nums1{1,3},nums2{2};
        VERIFY_CASE(obj.findMedianSortedArrays(nums1,nums2),2);
    }
    {
        vector<int> nums1{1,2},nums2{3,4};
        VERIFY_CASE(obj.findMedianSortedArrays(nums1,nums2),2.5);
    }

}