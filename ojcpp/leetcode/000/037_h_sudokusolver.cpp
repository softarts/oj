//
// Created by rui zhou on 2020-01-08.
//

/*
 * 9 x 9 sudoku solver
 * DFS
 */
#include <codech/codech_def.h>
#include <bitset>

using namespace std;

namespace {
    class Solution0 {
    public:
        void solveSudoku(vector<vector<char>>& board) {
            if (helper(board,0)) {
                for (int i=0;i<9;i++) {
                    for (int j=0;j<9;j++) {
                        cout << board[i][j] << " ";
                    }
                    cout << endl;
                }
            } else {
                cout << "No Solution\n";
            }
        }


        bool helper(vector<vector<char>> &board, int next_pos) {
            if (next_pos>=81) {
                return true;
            }

            int row = next_pos / 9;
            int col = next_pos %9;
            if (board[row][col] != '.') {
                return helper(board, next_pos+1);
            }


            for (int i=1;i<=9;i++) {
                board[row][col] = '0'+i;
                if (check(board,row,col)) {
                    if (helper(board, next_pos+1))
                        return true;
                }
            }
            board[row][col] = '.';
            return false;
        }

        bool rowcheck(vector<vector<char>> &board, int row) {
            unordered_set<char> m;
            for (int i=0;i<9;i++) {
                if (m.count(board[row][i]))
                    return false;
                else if (board[row][i]!='.'){
                    m.emplace(board[row][i]);
                }
            }
            return true;
        }

        bool colcheck(vector<vector<char>> &board, int col) {
            unordered_set<char> m;
            for (int i=0;i<9;i++) {
                if (m.count(board[i][col]))
                    return false;
                else if (board[i][col]!='.'){
                    m.emplace(board[i][col]);
                }
            }
            return true;
        }

        bool boxcheck(vector<vector<char>> &board, int row, int col) {
            row = row/3;
            col = col/3;
            unordered_set<char> m;
            for (int i=3*row;i<3*(row+1);i++) {
                for (int j=3*col;j<3*(col+1);j++) {
                    if (m.count(board[i][j]))
                        return false;
                    else if (board[i][j]!='.'){
                        m.emplace(board[i][j]);
                    }
                }
            }
            return true;
        }


        bool check(vector<vector<char>> &board, int row, int col) {
            return (rowcheck(board,row) && colcheck(board,col) && boxcheck(board,row,col));
        }
    };


    // improvement
    class Solution {
    public:
        bitset<9> rowcheck[9], colcheck[9], matcheck[3][3];
        void solveSudoku(vector<vector<char>>& board) {
            for (int row = 0; row < 9; row++)
                for (int col = 0; col < 9; col++)
                    if (board[row][col] != '.')
                    {
                        int v = board[row][col] - '0' - 1;
                        rowcheck[row].set(v);
                        colcheck[col].set(v);
                        matcheck[row / 3][col / 3].set(v);
                    }



            if (helper(board,0)) {
                for (int i=0;i<9;i++) {
                    for (int j=0;j<9;j++) {
                        cout << board[i][j] << " ";
                    }
                    cout << endl;
                }
            } else {
                cout << "No Solution\n";
            }
        }


        bool helper(vector<vector<char>> &board, int next_pos) {
            if (next_pos>=81) {
                return true;
            }

            int row = next_pos / 9;
            int col = next_pos %9;
            if (board[row][col] != '.') {
                auto v = board[row][col];
                rowcheck[row].set(v-'0'-1);
                colcheck[col].set(v-'0'-1);
                matcheck[row / 3][col / 3].set(v-'0'-1);
                return helper(board, next_pos+1);
            }


            for (int i=1;i<=9;i++) {
                auto v = '0'+i;
                if (isValid(board,row,col,v-'0'-1)) {
                    board[row][col] = v;
                    rowcheck[row].set(i-1);
                    colcheck[col].set(i-1);
                    matcheck[row / 3][col / 3].set(i-1);

                    if (helper(board, next_pos+1))
                        return true;

                    rowcheck[row].reset(i-1);
                    colcheck[col].reset(i-1);
                    matcheck[row / 3][col / 3].reset(i-1);
                }

            }
            board[row][col] = '.';
            return false;
        }

        bool isValid(vector<vector<char>> &board, int row, int col, int val) {
            if (rowcheck[row].test(val)){ return false; }
            if (colcheck[col].test(val)){ return false; }
            if (matcheck[row / 3][col / 3].test(val)){ return false; }
            return true;
        }
    };
}

DEFINE_CODE_TEST(037_sudokusolver)
{
    Solution obj;
    {
        vector<vector<char>> board = {
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
        };
        obj.solveSudoku(board);
    }

}
