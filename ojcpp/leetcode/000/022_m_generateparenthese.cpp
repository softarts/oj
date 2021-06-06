//
// Created by Rui Zhou on 4/4/18.
//

/*
 * https://leetcode.com/problems/generate-parentheses/description/
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

 10:14am->
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace std;
using namespace CODECH;

class Solution0 {
public:
    /* can not handle this:  "(()())",
    vector<string> generateParenthesis(int n) {
        vector<vector<int>> res;
        vector<int> comb;
        vector<string> combParenthesis;
        for (int i=1; i<=n; i++) {
            for (int j=n;j>0;j--) {
                dfs(res, comb, n, i);
            }
        }
        for (auto &v: res) {
            string s="";
            for (auto &it: v) {
                s+=printParenthesis(it);
            }
            combParenthesis.push_back(s);
        }
        return combParenthesis;
    }

    void dfs(vector<vector<int>> &res, vector<int> &comb, int n, int m) {
        if (m==1) {
            comb.push_back(n);
            res.push_back(comb);
            comb.pop_back();
            return;
        }

        for (int i= 1; i <= n-m+1; i++) {
            comb.push_back(i);
            dfs(res, comb, n-i, m-1);
            comb.pop_back();
        }

    }

    string printParenthesis(int n) {
        string ret;
        for (int i=0;i<n;i++) {
            ret+="(";
        }
        for (int i=0;i<n;i++) {
            ret+=")";
        }
        return ret;
    }
     */


    // recursive
    /*
    vector<string> generateParenthesis(int n) {
        vector<string> comb;
        string res = "";
        next(comb, res, n, 0);
        return comb;
    }

    void next(vector<string> &comb, string &res, int m, int left) {
        if (m==1) {
            res += "()";
            for (int i=0;i<left;i++) {
                res+=")";
            }
            comb.push_back(res);
            return;
        }

        string copy = res + "(";
        next(comb, copy, m-1, left+1);

        copy = res + "()";
        next(comb, copy, m-1, left);  // not handle AB and BA comb case
    }
    */

    vector<string> generateParenthesis(int n) {
        vector<string> res, comb;
        addParenthesis(res, comb,0,0,n);
        return res;
    }

    void addParenthesis(vector<string> &res, vector<string> &comb, int left, int right, int n) {
        vector<string> vcopy(comb.begin(),comb.end());
        if (left < n) {
            vcopy.push_back("(");
            addParenthesis(res, vcopy, left+1, right, n);
            vcopy.pop_back();
        }

        if (right<left) {
            vcopy.push_back(")");
            addParenthesis(res, vcopy, left, right+1, n);
            vcopy.pop_back();
        }

        if (right == n) {
            std::ostringstream os;
            std::copy( vcopy.begin(), vcopy.end(), ostream_iterator<string>( os ) );
            res.push_back(os.str());
        }
    }

};

// 代码更简洁,仍然是使用DFS的做法
class Solution {
public:
    vector<string> res;
    int total;
    vector<string> generateParenthesis(int n) {
        total = n;
        dfs("", 0,0);
        return res;
    }

    void dfs(string comb, int left, int right) {
        if (left==total && right==total) {
            res.emplace_back(comb);
        }

        if (left<total) {
            dfs(comb+"(",left+1,right);
        }

        if (right<left) {
            dfs(comb+")",left,right+1);
        }

    }

};


DEFINE_CODE_TEST(022_generateparenthese)
{
    Solution obj;
    {
        vector<string> v = obj.generateParenthesis(3);
        for (auto &iter:v) {
            cout << iter << endl;
        }

    }
}