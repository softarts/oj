//
// Created by rui.zhou on 9/26/2019.
//

/* https://leetcode.com/problems/fraction-to-recurring-decimal/
 * Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"

 2/3 = 6..2

 除法的实现
 关键，如何取得重复部分
4/333 => 0.012012012 => 0.(012) 有可能多个重复序列
 40/333 =0.(120)
 400/333=>1.(201) => 400,670,40,400,670

 主要问题
 abs 对INT_MIN取反的时候会溢出
用hashmap记下已经遇过的余数，如果再次遇上同一个余数，表明进入循环
 */


#include <codech/codech_def.h>
using namespace std;

namespace {


    class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            unordered_map<long,long> map;
            string ret;
            queue<long> decimalst;
            int flag = ((numerator>0 &&denominator>0) || (numerator<0 &&denominator<0) )?1:-1;
            int64_t num1 = numerator>0?numerator:-((unsigned int)numerator);
            int64_t deno1 = denominator>0?denominator:-((unsigned int)denominator);

            int64_t ip = num1 / deno1;
            int64_t remain = num1 % deno1;

            ret = to_string(ip);
            if (remain!=0) {
                ret += ".";
            }

            while (map.count(remain)==0 && remain!=0) {
                int64_t quotient = remain*10 / deno1;
                int64_t mo = remain*10 % deno1;
                map[remain]=quotient;
                decimalst.emplace(remain);
                remain = mo;
            }


            while (!decimalst.empty()) {
                auto &ele = decimalst.front();
                if (ele==remain) {
                    ret+="(";
                }
                ret += to_string(map[ele]);
                decimalst.pop();
            }
            if (remain!=0) {
                ret+=")";
            }
            return flag<0&&ret!="0"?"-"+ret:ret;
            //return flag>0?ret:"-"+ret;
        }
    };
}

DEFINE_CODE_TEST(166_fraction_recurring_decimal) {
    Solution obj;
    {

        VERIFY_CASE(obj.fractionToDecimal(-2147483648,1),"-2147483648");
        VERIFY_CASE(obj.fractionToDecimal(-1,-2147483648),"0.0000000004656612873077392578125");
        VERIFY_CASE(obj.fractionToDecimal(4,333),"0.(012)");
        VERIFY_CASE(obj.fractionToDecimal(0,-5),"0");
        VERIFY_CASE(obj.fractionToDecimal(1,6),"0.1(6)");
        VERIFY_CASE(obj.fractionToDecimal(0,3),"0");
        VERIFY_CASE(obj.fractionToDecimal(2,3),"0.(6)");
        VERIFY_CASE(obj.fractionToDecimal(1,2),"0.5");
        VERIFY_CASE(obj.fractionToDecimal(2,1),"2");
    }

}


//            while (remain>0) {
//                int quotient = remain*10 / denominator;
//                int mo = remain*10 % denominator;
//                if (map.count(remain) && remain==mo) {
//                    ret+="("+ to_string(map[remain]) + ")";
//                    break;
//                }
//                map[remain] = quotient;
//                remain = mo;
//                ret+=to_string(quotient);
//            }

//    class Solution {
//    public:
//        string fractionToDecimal(int numerator, int denominator) {
//            unordered_map<int,int> map;
//            string ret;
//            int flag = ((numerator>0 &&denominator>0) || (numerator<0 &&denominator<0) )?1:-1;
//
//            numerator = abs(numerator);
//            int ip = numerator / denominator;
//            int remain = numerator % denominator;
//            ret = to_string(ip);
//            if (remain!=0) {
//                ret += ".";
//            }
//
//
//            while (remain>0) {
//                int quotient = remain*10 / denominator;
//                int mo = remain*10 % denominator;
//                if (remain==mo) {
//                    ret+="("+ to_string(quotient) + ")";
//                    break;
//                } else {
//                    ret+=to_string(quotient);
//                }
//                remain = mo;
//            }
//            return flag>0?ret:"-"+ret;
//        }
//    };