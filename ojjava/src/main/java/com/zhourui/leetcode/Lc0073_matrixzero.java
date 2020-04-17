package com.zhourui.leetcode;


public class Lc0073_matrixzero {
    //使用额外的一行来标记
    class Solution {
        public void setZeroes(int[][] matrix) {
            int row[]=new int[matrix.length];
            int col[]=new int[matrix[0].length];
            for (int i=0;i<matrix.length;i++) {
                for (int j=0;j<matrix[0].length;j++) {
                    if (matrix[i][j]==0) {
                        row[i] = 0;
                        col[j] = 0;
                    }
                }
            }
            // set zero
            for (int i=0;i<matrix.length;i++) {
                for (int j=0;j<matrix[0].length;j++) {
                    if (row[i]==0 || col[j]==0) {
                        matrix[i][j]=0;
                    }
                }
            }
        }
    }
    // 使用O(1)空间,需要用第一行第一列来保存信息
    // 需要避免第一行/列的0是由别的转化而来，不能再根据这个0再去转化别的数据(做二重转化）
    // 仍然使用第一行，第一列作为存储。
    // 首先标记第一行/列是否含有0，然后检查matrix，设置所在行列首为0
    // 行列首为0，只能设置,第一行的0所在的列设为0,第一列的0所在的行设为0，与前面的做法是全部行列设为0不同
    // 再根据标记来设置第一行/列
    class Solution1 {
        public void setZeroes(int[][] matrix) {
            int m = matrix.length;
            int n = matrix[0].length;
            int i, j;

            //先标记第一行和第一列是否有0
            boolean firstRow = false, firstCol = false;
            for (j = 0; j < n; j++) {
                if (0 == matrix[0][j]) {
                    firstRow = true;
                    break;
                }
            }
            for (i = 0; i < m; i++) {
                if (0 == matrix[i][0]) {
                    firstCol = true;
                    break;
                }
            }

            //从第二行第二列还是遍历，如果遇到0，则把它所在行和列的第一个值设为0
            for (i = 1; i < m; i++) {
                for (j = 1; j < n; j++) {
                    if (0 == matrix[i][j]) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            // 第一行的0所在的列设为0
            for (i=1;i<n;i++) {
                if (matrix[0][i]==0) {
                    for (j=0;j<m;j++) {
                        matrix[j][i] = 0;
                    }
                }
            }
            // 第一列的0所在的行设为0
            for (i=1;i<m;i++) {
                if (matrix[i][0]==0) {
                    for (j=0;j<n;j++) {
                        matrix[i][j] = 0;
                    }
                }
            }

            // 最后，如果第一行和第一列标记为true,将该行/列全部设为0
            if (firstRow) {
                for (j = 0; j < n; j++) {
                    matrix[0][j] = 0;
                }
            }
            if (firstCol) {
                for (i = 0; i < m; i++) {
                    matrix[i][0] = 0;
                }
            }
        }
    }
}
