//
// Created by rui.zhou on 2/24/2019.
//

/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
 由于横向纵向都是有序的，而且下一行的数字都比上一行大，因此可以采用O(LogN)
 从右上角开始查找
 也可以看作是一个list来binary search
 复杂度评估? O(N)?
 TODO binary search

 */
#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row==0) return false;
        int col = matrix[0].size();
        int r = 0;
        int c=col-1;
        while (r<row && c>=0) {
            if (matrix[r][c]==target)
                return true;
            else if (matrix[r][c]>target) {
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};

DEFINE_CODE_TEST(074_search2dmatrix)
{
    Solution obj;
    {
        vector<vector<int>> m{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
        VERIFY_CASE(obj.searchMatrix(m,3),true);
        VERIFY_CASE(obj.searchMatrix(m,13),false);
    }

}

