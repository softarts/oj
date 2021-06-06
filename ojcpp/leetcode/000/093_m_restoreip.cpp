//
// Created by rui.zhou on 3/8/2019.
//

/*
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
 */

#include <codech/codech_def.h>
using namespace std;

namespace lc093 {
    class Solution {
    public:
        void dfs(int pos, string&s, vector<string> &comb, vector<string> &ret) {
            if (comb.size()==4) {
                if (pos==s.length()) {
//                    ostringstream ss;
//                    copy(comb.begin(),comb.end(),ostream_iterator<string>(ss,"."));
//                    ret.emplace_back(ss.str());
                    ret.emplace_back(comb[0]+"."+comb[1]+"."+comb[2]+"."+comb[3]);
                }
                return;
            }

            if (pos>=s.length())
                return;
//            if (s[pos]=='0')
//                return;


            comb.emplace_back(s.substr(pos,1));
            dfs(pos+1,s,comb,ret);
            comb.pop_back();

            if (s[pos]!='0') {
                comb.emplace_back(s.substr(pos,2));
                dfs(pos+2,s,comb,ret);
                comb.pop_back();
            }

            if (s[pos]!='0') {
                int net = stoi(s.substr(pos, 3), nullptr, 10);
                if (net <= 255) {
                    comb.emplace_back(s.substr(pos, 3));
                    dfs(pos + 3, s, comb, ret);
                    comb.pop_back();
                }
            }
        }
        vector<string> restoreIpAddresses(string s) {
            vector<string> ret;
            vector<string> comb;
            dfs(0, s, comb, ret);
            return ret;
        }
    };
}

DEFINE_CODE_TEST(093_restoreip)
{
    lc093::Solution obj;
    {
        string s = "25525511135";
        const auto &ret = obj.restoreIpAddresses("25525511135");
        for (auto &el : ret) {
            cout <<el <<endl;
        }

        //Output: ["255.255.11.135", "255.255.111.35"]

        //VERIFY_CASE(VERIFY_VV(obj.restoreIpAddresses("25525511135"),exp),true);
    }
    {
        const auto &ret = obj.restoreIpAddresses("");
        for (auto &el : ret) {
            cout << el << endl;
        }
    }

}