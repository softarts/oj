//
// Created by rui zhou on 2019-11-22.
//

// 输入3，打印1，2，3...999
//考虑整数会溢出，


#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        bool increaseNumber(string &number) {
            int n = number.size();
            int carry = 0;
            number[n-1] += 1;
            for (int i=n-1;i>=0;i--) {
                int x=carry+number[i]-'0';
                carry = x/10;
                number[i] = x%10+'0';
            }
            if (carry>0) {
                //cout << "overflow\n";
                return false;
            }else {
                //cout << number << endl;
                auto pos = number.find_first_not_of('0');
                for (int i=pos;i<n;i++) {
                    cout << number[i];
                }
                cout << endl;
                return true;
            }
        }

        void printMaxDigits(int n) {
            string number(n,'0');
            //number[n-1] = '0';
            //cout << number << endl;

            while (increaseNumber(number)) {
            }
        }
    };
}

DEFINE_CODE_TEST(012_print1ton)
{
    Solution obj;
    {
        obj.printMaxDigits(3);
    }
}