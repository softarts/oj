/**
 * Created by rui.zhou on 04 Jun, 2020
 */
package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.*;
import java.util.stream.Collectors;


/**
 * 这题也是比较烦的一种, 并不一定是个正方型
 * 思路
 * @author zhou rui
 */

/*
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]Output: [1,2,3,6,9,8,7,4,5]

这个是矩形
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

// 需要处理好单行或者单列的情况
// 还是c++的做法比较好,每处理完一行就修改边界
public class Lc0054_spiralmatrix extends BaseSolution {
    class Solution {
        public List<Integer> spiralOrder(int[][] matrix) {
            if (matrix.length ==0) {
                return Collections.emptyList();
            }
            List<Integer> ret = new ArrayList();
            helper(0,0,matrix[0].length-1,matrix.length-1,ret, matrix);
            return ret;
        }

        void helper(int x0,int y0, int x1, int y1,List<Integer> ret, int [][]matrix) {
            if (x0>x1 ||y0>y1) {
                return;
            }

            if (y0==y1) {
                for (int i=x0;i<=x1;i++) {
                    ret.add(matrix[y0][i]);
                }
                return;
            } else if (x0==x1) {
                for (int i=y0;i<=y1;i++) {
                    ret.add(matrix[i][x0]);
                }
                return;
            }
            //top
            for (int i=x0;i<x1;i++) {
                ret.add(matrix[y0][i]);
            }
            // right
            for (int i=y0;i<y1;i++) {
                ret.add(matrix[i][x1]);
            }
            // bottom
            for (int i=x1;i>x0;i--) {
                ret.add(matrix[y1][i]);
            }
            //left
            for (int i=y1;i>y0;i--) {
                ret.add(matrix[i][x0]);
            }

            helper(x0+1,y0+1,x1-1,y1-1, ret, matrix);
        }
    }

    @Override
    public boolean test() {
        Solution slu = new Solution();
        boolean ret = true;

        int [][]matrix = {{ 1,2,3,4,5,6,7,8,9,10}};
        List<Integer> lst = slu.spiralOrder(matrix);
        int expArr[]={1,2,3,4,5,6,7,8,9,10};
        List<Integer> exp = Arrays.stream(expArr).boxed().collect(Collectors.toList());
        ret &= lst.equals(exp);

        int [][]matrix1 = {{7},{9},{6}};
        List<Integer> lst1 = slu.spiralOrder(matrix);
        int expArr1[]={7,9,6};
        List<Integer> exp1 = Arrays.stream(expArr1).boxed().collect(Collectors.toList());
        ret &= lst1.equals(exp1);
        return ret;
    }
}
