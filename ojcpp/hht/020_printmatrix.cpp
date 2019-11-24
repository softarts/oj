//
// Created by rui zhou on 2019-11-24.
//

//lc 54
//需要注意那种非正方形的matrix,可能最后并不会形成一个回路，而是只有1行，或者一个数，
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
namespace {
    class Solution {
    public:
        vector<int> printmatrix(vector<vector<int>>& matrix) {
            vector<int> ret;
            int m = matrix.size();// row
            int n = matrix[0].size(); // column
            int left = 0,top=0,right=n-1,bottom=m-1;
            while (true) {
                if (left>right) break;
                for (int i=left;i<=right;i++) {
                    ret.emplace_back(matrix[top][i]);
                }

                if (top+1>bottom) break;
                for (int i=top+1;i<=bottom;i++) {
                    ret.emplace_back(matrix[i][right]);
                }

                if (right-1 < left) break;

                for (int i=right-1;i>=left;i--) {
                    ret.emplace_back(matrix[bottom][i]);
                }

                if (bottom-1 <= top) break;

                for (int i=bottom-1;i>top;i--) {
                    ret.emplace_back(matrix[i][left]);
                }

                left++;top++;right--;bottom--;
            }
            return ret;

        }
    };
}

DEFINE_CODE_TEST(020_printmatrix)
{
    Solution obj;
    {
        vector<vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
        VERIFY_CASE(PRINT_VEC(obj.printmatrix(m1)),"1 2 3 6 9 8 7 4 5");
    }

    {
        vector<vector<int>> m1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        VERIFY_CASE(PRINT_VEC(obj.printmatrix(m1)),"1 2 3 4 8 12 11 10 9 5 6 7");
    }

    {
        vector<vector<int>> m = {{ 1,2,3,4,5,6,7,8,9,10}};
        VERIFY_CASE(PRINT_VEC(obj.printmatrix(m)),"1 2 3 4 5 6 7 8 9 10");
    }
    {
        vector<vector<int>> m = {{ 3,2}};
        VERIFY_CASE(PRINT_VEC(obj.printmatrix(m)),"3 2");
    }
    {
        vector<vector<int>> m = {{ 5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
        VERIFY_CASE(PRINT_VEC(obj.printmatrix(m)),"5 1 9 11 10 7 16 12 14 15 13 2 4 8 6 3");
    }

    {
        vector<vector<int>> m = {};
        VERIFY_CASE(PRINT_VEC(obj.printmatrix(m)),"");
    }


}