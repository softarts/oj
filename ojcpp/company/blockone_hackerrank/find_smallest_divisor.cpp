//
// Created by rui.zhou on 5/20/2020.
//

// 两个字符 bcdbcdbcdbcd, bcdbcd
// 后者链接2次得到前者，所以能够除掉
// 要找出一个公约数，能够用其构造出s和t,返回长度
#include <codech/codech_def.h>

using namespace std;

namespace {
    //有问题，可能还可以分解
    string findDupStr(string &s) {
        int divisor = 2;
        while (s.length()/divisor>0){
            if(s.length()%divisor!=0){
                divisor++;
                continue;
            }else {
                auto subs = s.substr(0,s.length()/divisor);
                string s0 = "";
                for(int i=0;i<divisor;i++){
                    s0+=subs;
                }
                if (s0==s)
                    return findDupStr(subs);
                divisor++;
            }
        }
        return s;
    }

    string kmp(string &s) {
        int l = s.length();
        vector<int> next(l,0); //= new int[l];
        next[0] = -1;
        int i, j = -1;
        for (i = 1; i < l; i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
        int lenSub = l - 1 - next[l - 1];

        //(lenSub != l && l % lenSub ==0) {
         return s.substr(0,lenSub);

    }

    int findSmallestDivisor(string s, string t) {
        if (s.length()<t.length()) return -1;
        int tl = t.length();
        int pos = 0;
        while (pos < s.length()) {
            if (s.substr(pos,tl)!=t) {
                return -1;
            }
            pos += tl;
        }
        auto subs0 = findDupStr(t);
        return subs0.length();
    }
}


DEFINE_CODE_TEST(blockone_find_smallest_divisor)
{
    VERIFY_CASE(findSmallestDivisor("abcabc","abc"),3);


}