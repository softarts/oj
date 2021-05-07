#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        //TLE
        //
        int countBinarySubstrings0(string s) {
            int res = 0;
            int c[2]={1,-1};
            for (int i=0;i<s.size();i++) {
                int sum = 0;
                int pos = i;
                
                int prev = s[pos];
                int group=0;

                while (pos<s.size() && group<2) {
                    if (s[pos]!=prev) {
                        group++;
                        prev = s[pos];
                        if (group==2) break;
                    } 
                    sum+=c[s[pos]-'0'];
                    pos++;
                    if (sum==0) break;
                }
                if (sum==0) {
                    //cout << s.substr(i,pos-i) <<endl;
                    res++;
                }
            }
            return res;
        }
        //
        // cool 很精彩的解法，主要是方法问题
        // 计算每一个连续字符的个数，当遇到不同的时候转换prev和cur
        // 比较prev 和cur,只要prev>=cur表明可以有一个结果，这是关键步骤
        // 感觉这题应该是medium
        int countBinarySubstrings(string s) {
            int ret=0,cur=1,prev=0;
            for (int i=1;i<s.size();i++) {
                if (s[i]==s[i-1]) {
                    cur++;
                }else {
                    prev = cur;
                    cur=1;
                }
                if (prev>=cur) ret++;
            }
            return ret;
        }
    };
}


DEFINE_CODE_TEST(696_countbinary)
{
    Solution obj;
    VERIFY_CASE(obj.countBinarySubstrings("00110011"),6);
    VERIFY_CASE(obj.countBinarySubstrings("10101"),4);
    
    
}