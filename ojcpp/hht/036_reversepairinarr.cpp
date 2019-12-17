//
// Created by rui.zhou on 2019/12/17.
//

/*
 * {7,5,6,4} 中存在{7,6} {7,5}, {7,4},{5,4},{6,4} 5个逆序对
 * 暴力法 O(N^2)
 * merge sort 归并排序
 *  lc439 hard
 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int ans = 0;
        int reversePairs(vector<int>& nums) {
            ans = 0;
            int len = nums.size();
            vector<int> temp(len);
            mergeSort(nums, temp, 0, len-1);
            return ans;

        }
        void mergeSort(vector<int> &arr, vector<int>&dest, int begin,int end) {
            if (begin < end) {
                int mid = (begin+end)/2;
                mergeSort(arr,dest,begin, mid);
                mergeSort(arr,dest, mid + 1, end);
                mergeArray(arr, dest, begin, mid, end);
            }
        }

        void mergeArray(vector<int> &arr, vector<int>&dest, int begin,int mid, int end) {
            int i = begin;
            int j = mid+1;
            int k = 0;
            while (i<=mid && j<=end) {
                if (arr[i]<arr[j]) {
                    dest[k++] = arr[i++];
                } else {
                    ans += mid-i+1;
                    dest[k++] = arr[j++];
                }
            }
            while (i<=mid) {
                dest[k++] = arr[i++];
            }
            while (j<=end) {
                dest[k++] = arr[j++];
            }
            //copy back
            for (int i=0;i<k;i++) {
                arr[begin+i] = dest[i];
            }
        }
    };
}

DEFINE_CODE_TEST(036_reversepair)
{

}