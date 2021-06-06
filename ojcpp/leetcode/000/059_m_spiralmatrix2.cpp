//
// Created by rui.zhou on 3/12/2019.
//

/*
 * Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
namespace lc059 {
//    class Solution {
//    public:
//        vector<vector<int>> generateMatrix(int n) {
//            int start=0,end=n-1,cur=1;
//            vector<vector<int>> m(n,vector<int>(n,0));
//            while (start<=end) {
//                for (int i=start;i<=end;i++) {
//                    m[start][i]=++cur;
//                    m[i][end]=cur+(n-1);
//                    m[n-1-start][n-1-i]=cur+(n-1)+(n-1);
//                    m[n-1-i][start]=cur+(n-1)+(n-1)+(n-1);
//                }
//                cur+=(end-start+1)
//                start++;end--;
//            }
//        }
//    };
     //生成一个旋转矩阵
    //5:42 pm - 6:03
    class Solution0 {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> m(n, vector<int>(n, n*n));
            int start=0,end=n-1,cur=0;
            while (start<=end) {
                for (int i=start;i<end;i++) {
                    m[start][i]=++cur;  //top
                }
                for (int i=start;i<end;i++) {
                    m[i][end]=++cur;  //right
                }
                for (int i=start;i<end;i++) {
                    m[n-start-1][n-i-1]=++cur;  //bottom
                }
                for (int i=start;i<end;i++) {
                    m[n-i-1][start]=++cur;  //left
                }
                start++;end--;
            }
            return m;
        }
    };

    // 一个直观的四个方向旋转的思路，写了大概30分钟
    //就是先右-下-左-上-右，每次碰到已访问的节点，就变向
    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> m(n,vector<int>(n,0));
            int cur=0;
            int dx[]={1,0,-1,0};
            int dy[]={0,1,0,-1};
            int row=0,col=0,dir=0;
            while (true) {
                if (m[row][col]==0) { //未设置过
                    m[row][col]=++cur;
                    if (cur==n*n)
                        break;
                }
                int next_row=row+dy[dir];
                int next_col=col+dx[dir];
                if (next_row<0||next_col<0||next_row>=n||next_col>=n ||(m[next_row][next_col]!=0)) {
                    dir++;//变向
                    if (dir>=4) dir=0;
                    row+=dy[dir];
                    col+=dx[dir];
                } else {
                    row+=dy[dir];
                    col+=dx[dir];
                }
            }
            return m;
        }
    };
}
DEFINE_CODE_TEST(059_spiralmatrix2)
{
    lc059::Solution0 obj;
    {
        auto &&vv= obj.generateMatrix(3);
        cout<< PRINT_MATRIX(vv);
    }
    {
        auto &&vv= obj.generateMatrix(4);
        cout<< PRINT_MATRIX(vv);
    }
}