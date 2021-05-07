//
// Created by rui zhou on 28/03/18.
//


/*
 * https://leetcode.com/problems/rotate-image/description/
 * You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

 0,0 -> 2,0;
 1,0 -> 2,1;
 2,0 -> 2,2

 i,j -> n-j,i



 */

#include <codech/codech_def.h>
#include <iostream>
#include <sstream>
#include <codech/codech_util.h>

using namespace std;
using namespace CODECH;

//void printmatrix(vector<vector<int>> &m) {
//    for (auto &row : m){
//        for (auto &v : row) {
//            cout << v << " ";
//        }
//        cout << endl;
//    }
//}
//
//string verifymatrix(vector<vector<int>> &m) {
//    stringstream ss;
//    for (auto &row : m){
//        for (auto &v : row) {
//            ss << v << " ";
//        }
//    }
//    return trim(ss.str());
//}

// 思路， 从左到右，先外后内，
//采用swap的方法，固定用top edge来保存swap后的结果.
//适用于奇偶数
class Solution0 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        int start = 0, end = n;
        while (start<end) {
            for (int i=start;i<end;i++) {
                swap(matrix[start][i], matrix[i][n-start]); // A->B
                swap(matrix[start][i], matrix[end][n-i]);  // B->C
                swap(matrix[start][i], matrix[n-i][start]);  //C(A)->D
            }
            start++;end--;
        }
    }
};

//重写，把对应的连线画出来
//
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        int start = 0, end = n;
        while (start<end) {
            for (int i=start;i<end;i++) {
                swap(matrix[start][i],matrix[i][end]);
                swap(matrix[start][i],matrix[end][n-i]);
                swap(matrix[start][i],matrix[n-i][start]);
            }
            start++;end--;
        }
    }












    // 考虑多个正方形叠加，因此需要start和end来判断起始位置
    // end 不要等于n，既要留出最后一个元素的空间
    void rotate0(vector<vector<int>>& matrix) {
        int n=matrix.size()-1;
        int start=0,end=n;
        while (start<end) {
            for (int i=start;i<end;i++) {//注意起始条件
                swap(matrix[start][i],matrix[i][end]);
                swap(matrix[start][i],matrix[end][n-i]);  // 如果y用end-i的话会变得双重计算，因为i已包含了start的结果 
                swap(matrix[start][i],matrix[n-i][start]);
            }
            start++;end--;
        }
        
    }
    
};

DEFINE_CODE_TEST(048_rotateimage)
{
    Solution obj;
    {
        vector<vector<int>> i1 = {{ 4,8},{3,6}};
        obj.rotate(i1);
        VERIFY_CASE(PRINT_VVEC(std::move(i1)),"3 4 6 8");
    }

    {
        vector<vector<int>> i1 = {{1,2,3},{4,5,6},{7,8,9}};
        obj.rotate(i1);
        VERIFY_CASE(PRINT_VVEC(std::move(i1)),"7 4 1 8 5 2 9 6 3");
    }

    {
        vector<vector<int>> i1 = {{ 5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
        obj.rotate(i1);
        VERIFY_CASE(PRINT_VVEC(std::move(i1)),"15 13 2 5 14 3 4 1 12 6 8 9 16 7 10 11");
    }
}