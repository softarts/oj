//
// Created by rui.zhou on 3/14/2019.
//

/* union find
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

// 并查集,
// 尝试BFS解决

namespace lc130 {
    class UnionFind {
    private:
        vector<int> id;  //parent
        vector<int> sz;  //
        int count_;
    public:
        UnionFind(int n) {
            id.resize(n);
            sz.resize(n);
            count_=n;
            for (int i = 0; i < n; ++i)
            {
                id[i] = i;
                sz[i] = 1;
            }
        }
        int find(int x) {
            while (x!=id[x]) {
                id[x]=id[id[x]];
                x=id[x];
            }
            return x;
        }
        //merge
        void connect(int p,int q) {
            int i=find(p);
            int j=find(q);
            if (i==j) return;
            if(sz[i] < sz[j])  //large set as the new parent
            {
                id[i] = j;
                sz[j] += sz[i];
            }
            else
            {
                id[j] = i;
                sz[i] += sz[j];
            }
            count_--;
        }
        bool connected(int p, int q)                // check if two union is connected
        {
            return find(p) == find(q);
        }
    };
    class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            int m=board.size();
            if (m==0) return;
            int n=board[0].size();
            UnionFind uf(n*m+1); //last one is dummy node
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if ((i==0||j==0||i==m-1||j==n-1) && board[i][j]=='O') {
                        uf.connect(i*n+j,n*m);
                    }else if (board[i][j]=='O'){ //connect to neighbour 'O'
                        if (board[i-1][j]=='O') {
                            uf.connect(i*n+j,(i-1)*n+j);
                        }
                        if (board[i+1][j]=='O') {
                            uf.connect(i*n+j,(i+1)*n+j);
                        }
                        if (board[i][j-1]=='O') {
                            uf.connect(i*n+j,i*n+j-1);
                        }
                        if (board[i][j+1]=='O') {
                            uf.connect(i*n+j,i*n+j+1);
                        }
                    }
                }
            }
            for (int i=0;i<m;i++) {
                for (int j = 0; j < n; j++) {
                    if (!uf.connected(i*n+j,n*m)) {
                        board[i][j]='X';
                    }
                }
            }
        }
    };


    // BFS
    class Solution1 {
    public:
        void solve(vector<vector<char>> &board) {
            int row=board.size();
            if (row==0) return;
            int col=board[0].size();
            vector<pair<int,int>> oxy;
            for (int i=0;i<row;i++) {
                if (board[i][0]=='O') {
                    oxy.emplace_back(i,0);
                }
                if (board[i][col-1]=='O') {
                    oxy.emplace_back(i,col-1);
                }
            }
            for (int i=0;i<col;i++) {
                if (board[0][i]=='O') {
                    oxy.emplace_back(0,i);
                }
                if (board[row-1][i]=='O') {
                    oxy.emplace_back(row-1,i);
                }
            }
            while (!oxy.empty()) {
                auto &iter = oxy.back();
                int x = iter.first;int y = iter.second;
                board[x][y]='Y';
                oxy.pop_back();
                if(x>0 && board[x-1][y] == 'O' ) {oxy.emplace_back(x-1,y);}
                if(x<row-1 && board[x+1][y] == 'O' ) {oxy.emplace_back(x+1,y);}
                if(y>0 && board[x][y-1] == 'O' ) {oxy.emplace_back(x,y-1);}
                if(y<col-1 && board[x][y+1] == 'O' ) {oxy.emplace_back(x,y+1);}
            }
//            for(int i =0; i< row; i++)
//                48:            {
//                49:                 for(int j =0; j< col; j++)
//                    50:                 {
//                    51:                      if(board[i][j] =='O') board[i][j] = 'X';
//                    52:                      if(board[i][j] == 'Y') board[i][j] = 'O';
//                    53:                 }
//                54:            }

        }
    };
}

DEFINE_CODE_TEST(130_surroundregion)
{
    {
        lc130::Solution obj;
        vector<vector<char>> grid{{'X','O','X','X'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'}};
        vector<vector<char>> exp{{'X','O','X','X'},{'O','X','X','X'},{'X','X','X','O'},{'O','X','X','X'},{'X','X','X','O'},{'O','X','O','X'}};
        obj.solve(grid);
        VERIFY_CASE(VERIFY_VV(std::move(grid),exp),true);
    }
    {
        lc130::Solution obj;
        vector<vector<char>> grid{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
        vector<vector<char>> exp{{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}};
        obj.solve(grid);
        VERIFY_CASE(VERIFY_VV(std::move(grid),exp),true);
    }

}