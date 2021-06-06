//
// Created by Rui Zhou on 10/4/18.
//

/*
 * https://leetcode.com/problems/spiral-matrix/description/
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

 [
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace CODECH;
using namespace std;

class Solution {
public:
    // not support one row matrix
    /*vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty())
            return ret;

        int m = matrix.size();
        int n = matrix[0].size();
        int tot = m*n;

        int sn = 0, en = n - 1;
        int sm = 0, em = m - 1;

        while (sn<en || sm < em) {
            for (int i=sn; i < en;i++)
                ret.push_back(matrix[sn][i]);

            for (int i=sm;i<em;i++)
                ret.push_back(matrix[i][n-1-sm]);

            for (int i=en;i>sn;i--)
                ret.push_back(matrix[em][i]);

            for (int i=em;i>sm;i--)
                ret.push_back(matrix[i][sn]);

            sn++;en--;
            sm++;em--;
        }

        if (m==n && ret.size()<tot) {
            ret.push_back(matrix[sn][en]);
        }
        return ret;
    }*/

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty())
            return ret;

        int m = matrix.size();  // row size
        int n = matrix[0].size();  // col size

        int top = 0, right = n - 1, bottom = m - 1, left = 0;

        while (true) {
            for (int col=left; col<=right; col++)
                ret.push_back(matrix[top][col]);

            if (++top>bottom)
                break;

            for (int row=top; row <=bottom; row++)
                ret.push_back(matrix[row][right]);

            if (--right < left)
                break;

            for (int col=right;col>=left;col--)
                ret.push_back(matrix[bottom][col]);

            if (--bottom < top)
                break;

            for (int row=bottom; row >=top; row--)
                ret.push_back(matrix[row][left]);

            if (++left>right)
                break;
        }
        return ret;
    }
};

DEFINE_CODE_TEST(054_spiral_matrix)
{
    Solution obj;
    {
        vector<vector<int>> m = {{ 1,2,3,4,5,6,7,8,9,10}};
        VERIFY_CASE(PRINT_VEC(obj.spiralOrder(m)),"1 2 3 4 5 6 7 8 9 10");
    }
    {
        vector<vector<int>> m = {{ 3,2}};
        VERIFY_CASE(PRINT_VEC(obj.spiralOrder(m)),"3 2");
    }

    {
        vector<vector<int>> m = {{ 5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
        VERIFY_CASE(PRINT_VEC(obj.spiralOrder(m)),"5 1 9 11 10 7 16 12 14 15 13 2 4 8 6 3");
    }
    {
        vector<vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
        VERIFY_CASE(PRINT_VEC(obj.spiralOrder(m1)),"1 2 3 6 9 8 7 4 5");
    }
}
