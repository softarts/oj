/**
 * Created by rui.zhou on 04 Jun, 2020
 */
package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;


//[
//    [1,2,3],
//    [4,5,6],
//    [7,8,9]
// ],
//
//    rotate the input matrix in-place such that it becomes:
// [
//    [7,4,1],
//    [8,5,2],
//    [9,6,3]
// ]
// 这题在flextrade,asus考过，还是挺难写的，应该把它归到难写的程序里
// 思路就是以一个正方形的方式来依次交换，一直使用top来作为临时存储,所以最外层使用一个while循环,
// 注意end 取matrix的最右侧
// 然后在一个for loop 里 交换n-1 个数据(即避开end),使用top作为缓存
// 缩减头尾，直到start和end相等
public class Lc0048_rotateimage extends BaseSolution {
    class Solution {
        public void rotate(int[][] matrix) {
            int m = matrix.length;
            int start=0,end=m-1;
            while (start<end) {
                for (int i=start;i<end;i++) {
                    int tmp = matrix[start][i];
                    matrix[start][i] = matrix[i][end];  // top & right
                    matrix[i][end] = tmp;

                    tmp = matrix[start][i];
                    matrix[start][i] = matrix[end][m-i-1];// top & bottom
                    matrix[end][m-i-1] = tmp;

                    tmp = matrix[start][i];
                    matrix[start][i] = matrix[m-i-1][start];
                    matrix[m-i-1][start] = tmp;  // top & left
                }
                start++;end--;
            }
        }
    }
}
