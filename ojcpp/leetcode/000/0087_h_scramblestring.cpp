//
// Created by rui.zhou on 5/12/2020.
//

// abc - bca 的问题，算法有点问题,好几种情况
// 1.需要前部和后部交叉对比 i和n-i
// 2.前部和前部，后部和后部
#include <codech/codech_def.h>
#include <algorithm>

using namespace std;

namespace {
    class Solution {
    public:
        bool isScramble(string s1, string s2) {
            return helper(s1,s2);
        }

        bool helper(string s1, string s2) {
            if (s1.length()!=s2.length()) return false;
            if (s1.length()==0) return true;
            string a1=s1;
            string a2=s2;
            reverse(a1.begin(),a1.end());
            if (s1==s2 || a1==a2) return true;
            sort(a1.begin(),a1.end());
            sort(a2.begin(),a2.end());
            if (a1!=a2) return false;
            int n=s1.length();
            for (int i=1;i<n;i++) {
                string b0 = s1.substr(0,i);
                string b1 = s1.substr(i);

                string c0 = s2.substr(0,i);
                string c1 = s2.substr(i);

                string c2 = s2.substr(n-i);
                string c3 = s2.substr(0,n-i);

                if ((helper(b0,c0) && helper(b1,c1)) || (helper(b0,c2) && helper(b1,c3))) {
                    return true;
                }
            }
            return false;
        }
    };
}

DEFINE_CODE_TEST(0087_scramble) {
    Solution obj;
    {
        VERIFY_CASE(obj.isScramble("abc","bca"),true);
        VERIFY_CASE(obj.isScramble("rgeat","great"),true);
    }
}