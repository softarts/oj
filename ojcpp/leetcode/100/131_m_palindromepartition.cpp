//
// Created by rui.zhou on 3/8/2019.
//

/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
 ?aaba-> aa,b,a /a,a,b,a?/a,aba?
 由于并没有限制长度
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;


namespace lc131 {
    // DP的方法
    class Solution0 {
    public:
        vector<vector<string>> res;
        void f(int i,vector<vector<bool>>& dp, vector<string>& cur, string& s){
            int n = s.length();
            if(i==n){
                res.push_back(cur);
                return;
            }
            for(int j=i ; j<n ; j++) {
                if (dp[i][j]) {
                    cur.push_back(s.substr(i, j - i + 1));
                    f(j + 1, dp, cur, s);
                    cur.pop_back();
                }
            }
        }

        vector<vector<string>> partition(string s) {
            int n = s.length();
            res.clear();
            vector<vector<bool>> dp (n, vector<bool>(n,0));
            for(int i=0 ; i<n ; i++)
                dp[i][i]=1;

            for(int l=1 ; l<n ; l++){
                for(int i=0,j=i+l ; j<n ; i++,j++){
                    if(s[i]==s[j]){
                        if(l==1) dp[i][j]=1;
                        else dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
            vector<string> temp;
            f(0,dp,temp,s);
            return res;
        }
    };

    //DP的做法，while loop的做法不适合这里，因为他没有把每个substr切开.
    class Solution {
    public:
        vector<vector<string>> ret;
        void dfs(vector<vector<int>> &dp, string &s, vector<string> &comb,int pos) {
            if (pos>=s.length()) {
                ret.emplace_back(comb);
                return;
            }
            for (int i=pos;i<s.length();i++) {
                if (dp[pos][i]) {
                    comb.emplace_back(s.substr(pos,i-pos+1));
                    dfs(dp,s,comb,i+1);
                    comb.pop_back();
                }
            }
        }

        vector<vector<string>> partition(string s) {
            ret.clear();
            vector<string> comb;
            vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
            for (int i=0;i<s.length();i++) {
                dp[i][i]=1;
                for (int j=0;j<i;j++) {
                    dp[j][i] = (s[j]==s[i] && i==j+1) || (dp[j+1][i-1] && s[j]==s[i]);
                }
            }
            dfs(dp,s,comb,0);
            return ret;
        }
    };
}

DEFINE_CODE_TEST(131_palindromepartition)
{
    lc131::Solution obj;
    {
        string s="aab";
        vector<vector<string>> exp{{"aa","b"},{"a","a","b"}};
        VERIFY_CASE(VERIFY_VV(obj.partition(s),exp),true);
    }
    {
        vector<vector<string>> exp{{"aa","b","a"},{"a","a","b","a"},{"a","aba"}};
        VERIFY_CASE(VERIFY_VV(obj.partition("aaba"),exp),true);
    }

}