//
// Created by rui.zhou on 2/24/2019.
//

/*
 * Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
 思路1.使用priorityqueue
 2.直接找到该数字，然后前后比较
 */

#include <codech/codech_def.h>
using namespace std;

// O(N)的解法
// 从两头开始去掉离得远的字符，直到剩下k个字符
class Solution0 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        while (arr.size()>k) {
            if (x-arr.front() <= arr.back()-x) {
                arr.pop_back();
            } else {
                arr.erase(arr.begin());
            }
        }
        return arr;
    }
};

// 二分法
// 目的是使left尽可能为数组的起始,取k个元素
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int left = 0, right = arr.size()-k;
        while(left < right){
            int mid = left + (right-left)/2;
            if(abs(arr[mid]-x)>abs(arr[mid+k]-x)){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return arr;
    }
};
//
//vector<int> ans;
//if (x<=arr[0]) {
//for (int i=0;i<k;i++) {
//ans.emplace_back(arr[i]);
//}
//return ans;
//} else if (x>=arr[arr.size()-1]) {
//for (int i=arr.size()-k;i<arr.size();i++) {
//ans.emplace_back(arr[i]);
//}
//return ans;
//} else {
//
//}
//
//int low=0,high=arr.size()-1;
//while (low <= high) {
//int mid = (low + high)/2;
//if (arr[mid] < x) {
//low = mid+1;
//} else if (arr[mid] > x) {
//high = mid-1;
//} else {
//break;
//}
//}
//
//// low is the number
//int count = 0;
//int left = low-1,right=;
//while (count < k) {
//if (left>=0 &&arr[left])
//}