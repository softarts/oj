//
// Created by rui zhou on 07/03/19.
//

/*
 * https://leetcode.com/problems/word-search/
 * Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
更优化的方案，记下所有对应开头的字母位置
建立4个方向，逐个测试,dfs，套路
 */

#include <codech/codech_def.h>

using namespace std;
namespace lc079 {
    class Solution {
    private:
        int aaa=10;
        string search;
        int m=0;
        int n=0;
        int dx[4]={-1,1,0,0};  //x-axis left,right,up,down
        int dy[4]={0,0,-1,1};
    public:
        bool dfs(int row,int col,int pos,vector<vector<char>>& board,vector<vector<bool>> &visited) {
            if (pos==search.length())
                return true;

            if (row>=0 && row<m && col>=0 && col<n && !visited[row][col] && board[row][col]==search[pos])
            {
                visited[row][col]=true;
                for (int i=0;i<4;i++) {
                    int nextRow = dy[i]+row;
                    int nextCol = dx[i]+col;
                    if (dfs(nextRow, nextCol, pos + 1,board, visited))
                        return true;
                }
                visited[row][col]=false;
            }
            return false;
        }

        bool exist(vector<vector<char>>& board, string word) {
            if (board.empty() || word.empty())
                return false;
            m=board.size();
            n=board[0].size();
            search=word;
            vector<vector<bool>> visited(m,vector<bool>(n,false));
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (dfs(i,j,0,board,visited))
                        return true;
                }
            }
            return false;
        }
    };
}

DEFINE_CODE_TEST(079_searchword)
{
    lc079::Solution obj;
    {
        vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        VERIFY_CASE(obj.exist(board,""),false);
        VERIFY_CASE(obj.exist(board,"ABCCED"),true);
        VERIFY_CASE(obj.exist(board,"SEE"),true);
        VERIFY_CASE(obj.exist(board,"ABCB"),false);

    }
}