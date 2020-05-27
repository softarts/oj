//
// Created by rui zhou on 2020-05-21.
//

#include <codech/codech_def.h>
#include <unordered_set>


//You have been given a special kind of lock to open called a "Scrolling Combination Lock". The lock has 9 keys numbered from 1 to 9. Additionally, there are two numbers printed below the keys suggesting a range of values. To open the lock, you must enter all the numbers in the range that are "Scrolling Numbers".
//
//A Scrolling Number is a number that has two characteristics:
//
//No digits repeat themselves
//All digits in the number "scroll" through themselves
//How To Scroll
//        Beginning with the leftmost digit, take that digit's value DD and move DD digits to the right. When scrolling, if the last digit of the number is reached, wrap back to the leftmost digit as many times as needed to move to total of DD digits. After scrolling to a new digit, repeat the process using the new digit's value for DD.
//
//A Scrolling Number will visit every digit exactly once and end at the leftmost digit.
//
//For example, consider the Scrolling Number 6231.
//
//Start with the digit '6'
//Advance 6 steps, wrapping around once, to the digit '3'
//From '3', advance to '2', again wrapping around once
//From '2', advance to '1'
//From '1', advance to '6' in a final wrap
//输入：
//The input is the range of integers to consider for the lock, expressed in the format: A,BA,B
//
//        Each integer AA and BB is 1 <= AA <= BB <= 10000.
//
//输出：
//Print all Scrolling Numbers between AA and BB, inclusive, each on a single line. These are the combinations that will open the lock.
//
//If there are no Scrolling Numbers between AA and BB, print -1.
//
//测试 1
//测试输入
//        下载测试 1 输入
//100,500
//预期输出
//        下载测试 1 输入
//147
//174
//258
//285
//417
//471
//测试 2
//测试输入
//        下载测试 2 输入
//1000,2000
//预期输出
//        下载测试 2 输入
//1263
//1267
//1623
//1627
//测试 3
//测试输入
//        下载测试 3 输入
//1,1000
//预期输出
//        下载测试 3 输入
//1
//2
//3
//4
//5
//6
//7
//8
//9
//13
//15
//17
//19
//31
//35
//37
//39
//51
//53
//57
//59
//71
//73
//75
//79
//91
//93
//95
//97
//147
//174
//258
//285
//417
//471
//528
//582
//714
//741
//825
//852

// 简单讲就是6231 为例, 6 -->3 --> 2 ---> 1  --> 6
//
using namespace std;
namespace {
    void scroll(int l,int r) {
        for (int i=l;i<=r;i++) {
            string s = to_string(i);
            auto lens = s.size();
            int pos = 0, count = 0;
            int sset[10]={0};
            bool flag = true;
            while (count < lens) {
                if (sset[s[pos] - '0'] == 1 || s[pos]=='0') {
                    flag=false;
                    break;
                } else {
                    sset[s[pos] - '0'] = 1;
                }

                int newPos = (pos + s[pos] - '0') % lens;

                count++;
                if (newPos == pos && count<lens) {
                    flag=false;break;
                } else {
                    pos = newPos;
                }

            }

            if (s[pos] == s[0] && flag) {
                cout << s << endl;
            }
        }
    }

    int main() {
        string line;
        while(getline(cin,line)) {
            auto pos = line.find_first_of(',');
            auto l = line.substr(0,pos);
            auto r = line.substr(pos+1);
            scroll(atoi(l.c_str()),atoi(r.c_str()));
        }
    }


}

DEFINE_CODE_TEST(jpm_scrollnumber)
{
    //scroll(100,500);
    //scroll(1000,2000);
    scroll(1,1000);
    //input();


}
