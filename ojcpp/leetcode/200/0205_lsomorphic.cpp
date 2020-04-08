//
// Created by rui zhou on 2020-04-08.
//
#include <codech/codech_def.h>

using namespace std;

namespace {
    class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            unordered_map<char,char> m;
            unordered_map<char,char> n;

            for (int i=0;i<s.length();i++) {
                if (m.count(s[i])) {
                    if (m[s[i]]!=t[i]) return false;
                } else if (n.count(t[i])) {
                    if (n[t[i]]!=s[i]) return false;
                } else {
                    m[s[i]]=t[i];
                    n[t[i]]=s[i];
                }
            }
            return true;
        }
    };
}

DEFINE_CODE_TEST(205_lsomorphic)
{
    Solution obj;
    {
        VERIFY_CASE(obj.isIsomorphic("aa","ab"), false);
        VERIFY_CASE(obj.isIsomorphic("paper","title"), true);
        VERIFY_CASE(obj.isIsomorphic("foo","bar"), false);
        VERIFY_CASE(obj.isIsomorphic("egg","add"), true);

    }
}