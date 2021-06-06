//
// Created by Rui Zhou on 9/4/18.
//

/*
 * https://leetcode.com/problems/valid-sudoku/description/
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

#include <codech/codech_def.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9]={0}, block[9][9]={0};
        for (int i=0; i<board.size();i++) {
            for (int j=0;j<board.size();j++) {
                int c = board[i][j];
                if (c!='.') {
                    int n = c-'0'-1;
                    int b = j/3*3 + i /3;
                    if (row[i][n] || col[j][n] || block[b][n])
                        return false;
                    row[i][n] = 1;col[j][n] = 1; block[b][n] = 1;
                }

            }
        }
        return true;
    }
};


DEFINE_CODE_TEST(036_validsudoku)
{
    Solution obj;
    {
        
        vector<vector<char>> board={{'.','8','7','6','5','4','3','2','1'},{'2','.','.','.','.','.','.','.','.'},{'3','.','.','.','.','.','.','.','.'},{'4','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','.','.'},{'6','.','.','.','.','.','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'8','.','.','.','.','.','.','.','.'},{'9','.','.','.','.','.','.','.','.'}};
        VERIFY_CASE(obj.isValidSudoku(board),true);
    }

}