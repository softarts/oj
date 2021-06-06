//
// Created by Rui Zhou on 6/4/18.
//

/*
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 * Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
给出一个电话9宫格拨号键盘，1->"",2->"abc",3->"def"...9->"wxyz"
 当输入23的时候，可能有什么样的字母组合

 * */

/*
 * int tot = 1;
        for (int i=0;i<digits.length();i++) {
            if (!m[digits[i]-'0'].empty())
                tot *= m[digits[i]-'0'].length();
        }
        vector<string> ret(tot,"");
        for (int i=0;i<digits.length();i++) {
            string &pc = m[digits[i]-'0'];
            int p = pc.length();
            if (p==0)
                continue;
            int num = tot;
            int offset = 0;
            for (int k=0;k<num;k++) {
                for (int j=0; j< p ; j++) {
                    ret[offset+j] +=  pc[j];
                }
                offset += p;
            }
        }
 */
#include <codech/codech_def.h>
//#include <codech/algo_common.h>
using namespace std;
using namespace CODECH;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> m{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ret;
        next(m, digits, ret, "", 0);
        return ret;
    }

    void next(vector<string> &m, string & digits, vector<string> &ret, string comb, int mi) {
        if (mi >=digits.size() ) {
            if (!comb.empty())
                ret.push_back(comb);
            return;
        }

        string &ms = m[digits[mi]-'0'];
        if (ms.empty()) {
            next(m, digits, ret, comb, mi+1);
        } else {
            for (int i=0; i < ms.length(); i++) {
                next(m, digits, ret, comb+ms[i], mi+1);
            }
        }
    }
};

//abc，def，ghi各选一个，有多少种组合方法,不适合于排列
//abc分别写入一个vector<string>,此时size=3,然后按照size来依次结合其它的字符
//TODO
class Solution1 {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
                                        {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> ret;
        for (int i=0;i<digits.length();i++) {
            string &choices = map[digits[i]];
            if (ret.size()==0) {// do initialization
                //string &choices = map[digits[i]];
                for (auto &ch : choices) {
                    ret.emplace_back(1,ch);
                }
                continue;
            }
            std::vector<string> tmp_result;
            for (int j=0;j<ret.size();j++) {
                for (auto &ch : choices) {
                    tmp_result.emplace_back(ret[j]+ch);
                }
            }
            ret = tmp_result;
        }
        return ret;
    }
};

DEFINE_CODE_TEST(017_lettercombination_phoneletter)
{
    Solution1 obj;
    {
        //ad ae af
        VERIFY_CASE(PRINT_STRVEC(obj.letterCombinations("123")),"ad ae af bd be bf cd ce cf ");
    }
    {
        VERIFY_CASE(PRINT_STRVEC(obj.letterCombinations("23")),"ad ae af bd be bf cd ce cf ");
    }
    {
        VERIFY_CASE(PRINT_STRVEC(obj.letterCombinations("0")),"");
    }
    {
        VERIFY_CASE(PRINT_STRVEC(obj.letterCombinations("")),"");
    }
    {
        VERIFY_CASE(PRINT_STRVEC(obj.letterCombinations("1234567890")),"");
    }

}